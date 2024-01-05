#ifndef GENETIC_ALGORITHM_CHROMOSOME_H
#define GENETIC_ALGORITHM_CHROMOSOME_H

#include <vector>

class Chromosome {
public:
    std::vector<int> tour;
    float fitness;

    Chromosome() :  fitness(0.0f) {}
};

#endif //GENETIC_ALGORITHM_CHROMOSOME_H
