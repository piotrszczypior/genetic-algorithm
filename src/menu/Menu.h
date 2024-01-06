#ifndef META_HEURISTIC_ALGORITHMS_MENU_H
#define META_HEURISTIC_ALGORITHMS_MENU_H

#include <vector>
#include <map>
#include "../model/CrossoverType.h"
#include "../model/MutationType.h"

namespace menu {
    std::map<int, CrossoverType> crossover_map = {
            {1, CrossoverType::PARTIALLY_MAPPED_CROSSOVER},
            {2, CrossoverType::PARTITION_CROSSOVER}
    };

    std::map<int, MutationType> mutation_map = {
            {1, MutationType::DISPLACEMENT_MUTATION},
            {2, MutationType::INSERTION_MUTATION}
    };

    void create_menu();

    void print_options();

    void print_result(int greedy_result, int algorithm_result, const std::vector<int> &path);
}

#endif //META_HEURISTIC_ALGORITHMS_MENU_H
