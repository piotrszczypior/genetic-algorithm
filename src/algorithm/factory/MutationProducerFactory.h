//
// Created by pszczypi on 13.01.2024.
//

#ifndef GENETIC_ALGORITHM_MUTATIONPRODUCERFACTORY_H
#define GENETIC_ALGORITHM_MUTATIONPRODUCERFACTORY_H


#include <list>
#include "../mutation/AbstractMutationProducer.h"
#include "../mutation/DisplacementMutationProducer.h"
#include "../mutation/ScrambleMutationProducer.h"

class MutationProducerFactory {
private:
    std::list<AbstractMutationProducer*> mutationProducers = {
            new DisplacementMutationProducer(),
            new ScrambleMutationProducer()
    };

public:
    AbstractMutationProducer* get(MutationType type) {
        return *std::find_if(mutationProducers.begin(), mutationProducers.end(),
                             [type](const AbstractMutationProducer* producer) {
                                 return producer->supports(type);
                             });
    }
};


#endif //GENETIC_ALGORITHM_MUTATIONPRODUCERFACTORY_H
