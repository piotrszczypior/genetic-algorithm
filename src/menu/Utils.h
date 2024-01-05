#ifndef META_HEURISTIC_ALGORITHMS_UTILS_H
#define META_HEURISTIC_ALGORITHMS_UTILS_H

#include <string>
#include <vector>

namespace utils {
    void clear_console();

    int get_input();

    void press_key_to_continue();

    std::string get_time_label(std::string time_label);

    void print_separator(int size);

    int calculate_path_characters_size(const std::vector<int> &path);
}

#endif //META_HEURISTIC_ALGORITHMS_UTILS_H
