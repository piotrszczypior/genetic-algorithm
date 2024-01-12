#ifndef GENETIC_ALGORITHM_ALGORITHMCONFIG_H
#define GENETIC_ALGORITHM_ALGORITHMCONFIG_H

#include "../../model/CrossoverType.h"
#include "../../model/MutationType.h"

class AlgorithmConfig {
public:
    int stopping_condition = 0;
    int population_size = 10;
    int generations_number{};
    float crossover_rate{};
    float mutation_rate{};
    CrossoverType crossover_type = CrossoverType::PARTIALLY_MAPPED_CROSSOVER;
    MutationType mutation_type = MutationType::DISPLACEMENT_MUTATION;
    int number_of_elites = 2;
    float elitism_percentage = 0.01;

    int calculate_number_of_elites() {
        return static_cast<int>(population_size * elitism_percentage);
    }
};

#endif //GENETIC_ALGORITHM_ALGORITHMCONFIG_H
