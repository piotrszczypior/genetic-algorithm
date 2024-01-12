//
// Created by pszczypi on 13.01.2024.
//

#ifndef GENETIC_ALGORITHM_CROSSOVERPRODUCERFACTORY_H
#define GENETIC_ALGORITHM_CROSSOVERPRODUCERFACTORY_H


#include <list>
#include <algorithm>
#include <memory>
#include "../crossover/AbstractCrossoverProducer.h"
#include "../crossover/OrderedCrossoverProducer.h"
#include "../crossover/PartiallyMappedCrossoverProducer.h"

class CrossoverProducerFactory {
private:
    std::list<AbstractCrossoverProducer*> crossoverProducers = {
            new OrderedCrossoverProducer(),
            new PartiallyMappedCrossoverProducer()
    };

public:
    AbstractCrossoverProducer* get(CrossoverType type) {
        return *std::find_if(crossoverProducers.begin(), crossoverProducers.end(),
                            [type](const AbstractCrossoverProducer* producer) {
                                return producer->supports(type);
                            });
    }
};


#endif //GENETIC_ALGORITHM_CROSSOVERPRODUCERFACTORY_H
