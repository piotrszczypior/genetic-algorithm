#ifndef GENETIC_ALGORITHM_GENETICALGORITHM_H
#define GENETIC_ALGORITHM_GENETICALGORITHM_H

#include "../model/CrossoverType.h"
#include "model/AlgorithmConfig.h"
#include "model/Result.h"
#include "../model/Graph.h"
#include "model/Chromosome.h"
#include "crossover/AbstractCrossoverProducer.h"
#include "mutation/AbstractMutationProducer.h"
#include <random>
#include <functional>

class GeneticAlgorithm {
private:
    Graph graph;
    AlgorithmConfig config;
    std::mt19937 generator{std::random_device{}()};
    Result result;

    AbstractCrossoverProducer* crossoverProducer;
    AbstractMutationProducer* mutationProducer;

    std::vector<Chromosome> initialize_population();

    const std::function<bool(const Chromosome &, const Chromosome &)> compare_chromosomes =
            [](const Chromosome &first, const Chromosome &second) -> bool {
                return first.fitness < second.fitness;
            };

    void evaluate_population(std::vector<Chromosome> &population);

    int calculate_fitness(const Chromosome &chromosome);

    std::vector<Chromosome> tournament_selection(const std::vector<Chromosome> &population);

    void evaluate_chromosome(Chromosome &chromosome);

    void evaluate_chromosomes(pair<Chromosome, Chromosome> &chromosomes);

    vector<Chromosome> select_elite_individuals(const vector<Chromosome> &population);

public:
    explicit GeneticAlgorithm(AlgorithmConfig config);

    Result process(const Graph &graph);
};


#endif //GENETIC_ALGORITHM_GENETICALGORITHM_H
