//
// Created by pszczypi on 13.01.2024.
//

#ifndef GENETIC_ALGORITHM_ABSTRACTMUTATIONPRODUCER_H
#define GENETIC_ALGORITHM_ABSTRACTMUTATIONPRODUCER_H


#include <random>
#include "../model/Chromosome.h"
#include "../../model/MutationType.h"

class AbstractMutationProducer {
protected:
    std::mt19937 generator{std::random_device{}()};

public:
    virtual ~AbstractMutationProducer() = default;

    virtual bool supports(MutationType type) const = 0;

    virtual void mutate(int city_number, Chromosome& chromosome) = 0;
};


#endif //GENETIC_ALGORITHM_ABSTRACTMUTATIONPRODUCER_H
