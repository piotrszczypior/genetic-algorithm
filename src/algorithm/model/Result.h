#ifndef GENETIC_ALGORITHM_RESULT_H
#define GENETIC_ALGORITHM_RESULT_H

#include <vector>

class Result {
public:
    int path_cost;
    std::vector<int> tour;

    Result() : path_cost(99999) {}
};

#endif //GENETIC_ALGORITHM_RESULT_H
