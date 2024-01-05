#include <fstream>
#include <regex>
#include <iostream>
#include "FileReader.h"

Graph FileReader::read_graph_from_xml_file(const std::string& file_path) {
    std::ifstream file(file_path);
    std::string line;
    std::regex edge_pattern(R"(<edge cost="([0-9.e+0-9]+)\">([0-9]+)<\/edge>)");
    std::smatch matches;
    int vertex_index = 0;

    if (!file.is_open()) {
        std::cerr << "There was a problem with xml file: " << file_path << std::endl;
        return {};
    }
    vector<vector<int>> matrix;
    bool is_first_run = true;
    while (getline(file, line)) {
        if (line.find("<vertex>") != std::string::npos) {
            matrix.emplace_back();
            if (!is_first_run) {
                vertex_index++;
            }
            is_first_run = false;
        } else if (std::regex_search(line, matches, edge_pattern) && matches.size() == 3) {
            auto cost = std::stod(matches[1]);
            matrix[vertex_index].push_back(static_cast<int>(cost));
        }
    }
    return Graph{matrix};
}
