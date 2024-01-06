#ifndef GENETIC_ALGORITHM_CHROMOSOME_H
#define GENETIC_ALGORITHM_CHROMOSOME_H

#include <vector>

class Chromosome {
public:
    std::vector<int> tour;
    int fitness;

    Chromosome() :  fitness(0) {}
};

#endif //GENETIC_ALGORITHM_CHROMOSOME_H
