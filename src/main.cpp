#include <iostream>
#include "algorithm/GeneticAlgorithm.h"
#include "file/FileReader.h"

using namespace std;

int main(int argc, char *argv[]) {

    auto graph = FileReader::read_graph_from_xml_file("../data/burma14.xml");
    AlgorithmConfig config = AlgorithmConfig();
    config.population_size = 100;
    config.crossover_rate = 0.8;
    config.mutation_rate = 0.01;
    config.stopping_condition = 120;

    GeneticAlgorithm ga = GeneticAlgorithm(config);

    auto result = ga.process(graph);
    cout << "Path cost: " << result.path_cost << endl;
}

//
//Chromosome first_offspring;
//Chromosome second_offspring;
//
//Chromosome p1 = Chromosome();
//p1.tour = {1, 2, 3, 4, 5, 6, 7, 8 ,9};
//
//Chromosome p2 = Chromosome();
//p2.tour = {4 ,5, 2, 1, 8, 7, 6, 9, 3};