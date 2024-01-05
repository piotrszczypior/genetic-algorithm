#include <string>
#include "../model/Graph.h"

#ifndef GENETIC_ALGORITHM_FILEREADER_H
#define GENETIC_ALGORITHM_FILEREADER_H


class FileReader {
public:
    static Graph read_graph_from_xml_file(const std::string& file_path);
};


#endif //GENETIC_ALGORITHM_FILEREADER_H
