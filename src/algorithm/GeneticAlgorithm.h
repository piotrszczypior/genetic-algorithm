#ifndef GENETIC_ALGORITHM_GENETICALGORITHM_H
#define GENETIC_ALGORITHM_GENETICALGORITHM_H


#include "../model/CrossoverType.h"
#include "../model/AlgorithmConfig.h"

class GeneticAlgorithm {
private:
    int population_size;
    int generations_number;
    float crossover_rate;
    float mutation_rate;
    CrossoverType selection_type;


public:
    GeneticAlgorithm(int populationSize, int generationsNumber, float crossoverRate, float mutationRate,
                     CrossoverType selectionType);

    explicit GeneticAlgorithm(AlgorithmConfig config);

    /**
     *
     *
     * */
    void process(int time_stop_criteria);
    
};


#endif //GENETIC_ALGORITHM_GENETICALGORITHM_H
