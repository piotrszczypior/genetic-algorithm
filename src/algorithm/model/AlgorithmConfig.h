#ifndef GENETIC_ALGORITHM_ALGORITHMCONFIG_H
#define GENETIC_ALGORITHM_ALGORITHMCONFIG_H

#include "../../model/CrossoverType.h"
#include "../../model/MutationType.h"

class AlgorithmConfig {
public:
    int stopping_condition = 0;
    int population_size = 10;
    float crossover_rate{};
    float mutation_rate{};
    CrossoverType crossover_type = CrossoverType::PARTIALLY_MAPPED_CROSSOVER;
    MutationType mutation_type = MutationType::DISPLACEMENT_MUTATION;
};

#endif //GENETIC_ALGORITHM_ALGORITHMCONFIG_H
