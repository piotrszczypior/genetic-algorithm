//
// Created by pszczypi on 13.01.2024.
//

#ifndef GENETIC_ALGORITHM_SCRAMBLEMUTATIONPRODUCER_H
#define GENETIC_ALGORITHM_SCRAMBLEMUTATIONPRODUCER_H


#include <unordered_set>
#include "AbstractMutationProducer.h"

class ScrambleMutationProducer : public AbstractMutationProducer {
public:
    bool supports(MutationType type) const override {
        return type == MutationType::SCRAMBLE_MUTATION;
    }

    void mutate(int city_number, Chromosome &chromosome) override {
        int scramble_size = 3;
        auto distribution = std::uniform_int_distribution<int>(1, city_number - 1);
        std::unordered_set<int> indexes_as_set;

        while (indexes_as_set.size() < scramble_size) {
            indexes_as_set.insert(distribution(generator));
        }
        vector<int> indexes(indexes_as_set.begin(), indexes_as_set.end());
        vector<int> cities_to_shuffle;
        for(auto const index : indexes) {
            cities_to_shuffle.push_back(chromosome.tour[index]);
        }

        std::shuffle(cities_to_shuffle.begin(), cities_to_shuffle.end(), generator);
        scramble_size = 0;
        for(auto const index : indexes) {
            chromosome.tour[index] = cities_to_shuffle[scramble_size];
            scramble_size++;
        }

        int start = std::uniform_int_distribution<int>(1, city_number - 3)(generator);
        int end = std::uniform_int_distribution<int>(start + 1, city_number - 1)(generator);
        std::shuffle(chromosome.tour.begin() + start, chromosome.tour.begin() + end, generator);
    }
};


#endif //GENETIC_ALGORITHM_SCRAMBLEMUTATIONPRODUCER_H
