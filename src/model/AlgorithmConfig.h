#ifndef GENETIC_ALGORITHM_ALGORITHMCONFIG_H
#define GENETIC_ALGORITHM_ALGORITHMCONFIG_H

#include "CrossoverType.h"
#include "MutationType.h"

class AlgorithmConfig {
public:
    int stopping_condition = 0;
    int population_size{};
    int generations_number{};
    float crossover_rate{};
    float mutation_rate{};
    CrossoverType crossover_type = CrossoverType::TOURNAMENT;
    MutationType mutation_type = MutationType::TOURNAMENT;
};

#endif //GENETIC_ALGORITHM_ALGORITHMCONFIG_H
