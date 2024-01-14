//
// Created by pszczypi on 13.01.2024.
//

#ifndef GENETIC_ALGORITHM_DISPLACEMENTMUTATIONPRODUCER_H
#define GENETIC_ALGORITHM_DISPLACEMENTMUTATIONPRODUCER_H


#include "AbstractMutationProducer.h"
#include <random>

class DisplacementMutationProducer : public AbstractMutationProducer {
public:
    bool supports(MutationType type) const override {
        return type == MutationType::DISPLACEMENT_MUTATION;
    }

    void mutate(int city_number, Chromosome &chromosome) override {
        int start = std::uniform_int_distribution<int>(1, city_number - 3)(generator);
        int end = std::uniform_int_distribution<int>(start + 1, city_number - 1)(generator);

        std::vector<int> subsequence(chromosome.tour.begin() + start, chromosome.tour.begin() + end);

        chromosome.tour.erase(chromosome.tour.begin() + start, chromosome.tour.begin() + end);

        int insertion_point = std::uniform_int_distribution<int>(1, city_number - int(subsequence.size()) - 1)(
                generator);

        chromosome.tour.insert(chromosome.tour.begin() + insertion_point, subsequence.begin(), subsequence.end());
    }
};


#endif //GENETIC_ALGORITHM_DISPLACEMENTMUTATIONPRODUCER_H
