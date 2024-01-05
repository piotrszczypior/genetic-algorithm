#include <chrono>
#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int populationSize, int generationsNumber, float crossoverRate, float mutationRate,
                                   CrossoverType selectionType) {
    population_size = populationSize;
    generations_number = generationsNumber;
    crossover_rate = crossoverRate;
    mutation_rate = mutationRate;
    selection_type = selectionType;

}

GeneticAlgorithm::GeneticAlgorithm(AlgorithmConfig config) {
    population_size = config.population_size;
    generations_number = config.generations_number;
    crossover_rate = config.crossover_rate;
    mutation_rate = config.mutation_rate;
    selection_type = config.crossover_type;
}

void GeneticAlgorithm::process(int time_stop_criteria) {
    auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration(time_stop_criteria);

    while (std::chrono::high_resolution_clock::now() - start_time < duration) {

    }
}
