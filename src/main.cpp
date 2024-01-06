#include <iostream>
#include "algorithm/GeneticAlgorithm.h"
#include "file/FileReader.h"

using namespace std;

int main(int argc, char *argv[]) {
    auto graph = FileReader::read_graph_from_xml_file("../data/ftv47.xml");
    AlgorithmConfig config = AlgorithmConfig();
    GeneticAlgorithm ga = GeneticAlgorithm(config);
    ga.process(graph);
}