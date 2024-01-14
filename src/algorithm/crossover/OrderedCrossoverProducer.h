//
// Created by pszczypi on 13.01.2024.
//

#ifndef GENETIC_ALGORITHM_ORDEREDCROSSOVERPRODUCER_H
#define GENETIC_ALGORITHM_ORDEREDCROSSOVERPRODUCER_H


#include <set>
#include "../../model/CrossoverType.h"
#include "AbstractCrossoverProducer.h"

class OrderedCrossoverProducer : public AbstractCrossoverProducer {
public:

    std::pair<Chromosome, Chromosome> crossover(int city_number,
                                                const Chromosome &first_chromosome,
                                                const Chromosome &second_chromosome) override {
        std::uniform_int_distribution<int> distribution(1, city_number - 1);
        Chromosome first_offspring, second_offspring;
        std::set<int> segments_indexes;
        while (segments_indexes.size() < 2) {
            segments_indexes.insert(distribution(generator));
        }

        first_offspring.tour = first_chromosome.tour;
        second_offspring.tour = second_chromosome.tour;
        vector<int> indexes(segments_indexes.begin(), segments_indexes.end());
        std::sort(indexes.begin(), indexes.end());
        for (int i = indexes[0]; i <= indexes[1]; ++i) {
            std::swap(first_offspring.tour[i], second_offspring.tour[i]);
        }

        const auto repair =
                [&](Chromosome &offspring, const Chromosome &parent) {
                    std::set<int> included(offspring.tour.begin() + indexes[0], offspring.tour.begin() + indexes[1] + 1);
                    int insert_index = indexes[1] + 1 == city_number ? 1 : indexes[1] + 1;
                    int city_index = indexes[1] + 1 == city_number ? 1 : indexes[1] + 1;

                    while (insert_index != indexes[0]) {
                        if (city_index == city_number) {
                            city_index = 1;
                        }
                        if (insert_index == city_number) {
                            if (indexes[0] == 1) {
                                break;
                            }
                            insert_index = 1;
                        }
                        auto city = parent.tour[city_index];
                        if (included.find(city) == included.end()) {
                            offspring.tour[insert_index] = city;
                            insert_index++;
                        }
                        city_index++;
                    }
                };
        repair(first_offspring, first_chromosome);
        repair(second_offspring, second_chromosome);
        return std::make_pair(first_offspring, second_offspring);
    }


    bool supports(CrossoverType type) const override {
        return type == CrossoverType::ORDERED_CROSSOVER;
    }
};


#endif //GENETIC_ALGORITHM_ORDEREDCROSSOVERPRODUCER_H
