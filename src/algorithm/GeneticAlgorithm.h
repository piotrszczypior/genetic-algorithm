#ifndef GENETIC_ALGORITHM_GENETICALGORITHM_H
#define GENETIC_ALGORITHM_GENETICALGORITHM_H

#include "../model/CrossoverType.h"
#include "../model/AlgorithmConfig.h"
#include "model/Result.h"
#include "../model/Graph.h"
#include "model/Chromosome.h"
#include <random>
#include <functional>

class GeneticAlgorithm {
private:
    Graph graph;
    AlgorithmConfig config;
    std::mt19937 generator{std::random_device{}()};

    Result result;

    std::vector<Chromosome> initialize_population();

    const std::function<bool(const Chromosome &, const Chromosome &)> compare_chromosomes =
            [](const Chromosome &first, const Chromosome &second) -> bool {
                return first.fitness < second.fitness;
            };


    void evaluate_population(std::vector<Chromosome> &population);

    int calculate_fitness(const Chromosome &chromosome);

    std::vector<Chromosome> tournament_selection(const std::vector<Chromosome> &population);

    void mutate(Chromosome &chromosome);

    void crossover(Chromosome &first_chromosome, Chromosome &second_chromosome, Chromosome &first_offspring,
                   Chromosome &second_offspring);

public:

    explicit GeneticAlgorithm(AlgorithmConfig config);

    Result process(const Graph &graph);

    vector<Chromosome> select_new_population(vector<Chromosome> population);
};


#endif //GENETIC_ALGORITHM_GENETICALGORITHM_H
