#ifndef GENETIC_ALGORITHM_ABSTRACTCROSSOVERPRODUCER_H
#define GENETIC_ALGORITHM_ABSTRACTCROSSOVERPRODUCER_H


#include "../../model/CrossoverType.h"
#include "../model/Chromosome.h"
#include <random>

class AbstractCrossoverProducer {
protected:
    std::mt19937 generator{std::random_device{}()};

public:
    virtual ~AbstractCrossoverProducer() = default;

    virtual bool supports(CrossoverType type) const = 0;

    virtual std::pair<Chromosome, Chromosome> crossover(int city_number,
                                                        const Chromosome& first_chromosome,
                                                        const Chromosome &second_chromosome) = 0;
};

#endif //GENETIC_ALGORITHM_ABSTRACTCROSSOVERPRODUCER_H
