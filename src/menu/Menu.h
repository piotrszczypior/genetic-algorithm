#ifndef META_HEURISTIC_ALGORITHMS_MENU_H
#define META_HEURISTIC_ALGORITHMS_MENU_H

#include <vector>
#include <map>
#include "../model/CrossoverType.h"
#include "../model/MutationType.h"
#include "../algorithm/model/AlgorithmConfig.h"
#include "../algorithm/model/Result.h"
#include <string>

namespace menu {
    static std::map<int, CrossoverType> crossover_map = {
            {1, CrossoverType::PARTIALLY_MAPPED_CROSSOVER},
            {2, CrossoverType::ORDERED_CROSSOVER}
    };

    static std::map<int, MutationType> mutation_map = {
            {1, MutationType::DISPLACEMENT_MUTATION},
            {2, MutationType::SCRAMBLE_MUTATION}
    };

    void create_menu();

    void print_options();

    std::string get_crossover_type(CrossoverType type);

    std::string get_mutation_type(MutationType type);

    void print_config(AlgorithmConfig config);

    void print_result(const Result& result);
}

#endif //META_HEURISTIC_ALGORITHMS_MENU_H
