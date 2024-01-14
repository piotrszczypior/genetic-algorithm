//
// Created by pszczypi on 13.01.2024.
//

#ifndef GENETIC_ALGORITHM_PARTIALLYMAPPEDCROSSOVERPRODUCER_H
#define GENETIC_ALGORITHM_PARTIALLYMAPPEDCROSSOVERPRODUCER_H

#include <random>
#include <unordered_map>
#include <random>
#include "../../model/CrossoverType.h"
#include "AbstractCrossoverProducer.h"

class PartiallyMappedCrossoverProducer : public AbstractCrossoverProducer {

    std::pair<Chromosome, Chromosome> crossover(int city_number,
                                                const Chromosome& first_parent,
                                                const Chromosome &second_parent) override {
        Chromosome first_offspring;
        Chromosome second_offspring;

        int first_crossover_point = std::uniform_int_distribution<int>(1, city_number - 3)(generator);
        int second_crossover_point = std::uniform_int_distribution<int>(first_crossover_point + 1, city_number - 1)(generator);

        first_offspring.tour = first_parent.tour;
        second_offspring.tour = second_parent.tour;

        for (int i = first_crossover_point; i <= second_crossover_point; ++i) {
            std::swap(first_offspring.tour[i], second_offspring.tour[i]);
        }

        const auto repair =
                [&](Chromosome &offspring, const Chromosome &first_parent, const Chromosome &second_parent) {
                    std::unordered_map<int, int> mapping;
                    for (int i = first_crossover_point; i <= second_crossover_point; ++i) {
                        mapping[first_parent.tour[i]] = second_parent.tour[i];
                    }

                    for (int i = 1; i < city_number; ++i) {
                        if (i >= first_crossover_point && i <= second_crossover_point) {
                            continue;
                        }

                        while (mapping.find(offspring.tour[i]) != mapping.end()) {
                            offspring.tour[i] = mapping[offspring.tour[i]];
                        }
                    }
                };

        repair(first_offspring, second_parent, first_parent);
        repair(second_offspring, first_parent, second_parent);
        return std::make_pair(first_offspring, second_offspring);
    }


    bool supports(CrossoverType type) const override {
        return type == CrossoverType::PARTIALLY_MAPPED_CROSSOVER;
    }
};


#endif //GENETIC_ALGORITHM_PARTIALLYMAPPEDCROSSOVERPRODUCER_H
