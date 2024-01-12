//
// Created by pszczypi on 13.01.2024.
//

#ifndef GENETIC_ALGORITHM_ORDEREDCROSSOVERPRODUCER_H
#define GENETIC_ALGORITHM_ORDEREDCROSSOVERPRODUCER_H


#include "../../model/CrossoverType.h"
#include "AbstractCrossoverProducer.h"

class OrderedCrossoverProducer : public AbstractCrossoverProducer {

    std::pair<Chromosome, Chromosome> crossover(int city_number,
                                                const Chromosome& first_chromosome,
                                                const Chromosome &second_chromosome) override {
        return std::make_pair(Chromosome(), Chromosome());
    }


    bool supports(CrossoverType type) const override {
        return type == CrossoverType::ORDERED_CROSSOVER;
    }
};


#endif //GENETIC_ALGORITHM_ORDEREDCROSSOVERPRODUCER_H
