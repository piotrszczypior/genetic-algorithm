#include <iostream>
#include "algorithm/GeneticAlgorithm.h"
#include "file/FileReader.h"
#include "file-writer/FileWriter.h"

using namespace std;

int main(int argc, char *argv[]) {

    auto graph = FileReader::read_graph_from_xml_file("../data/ftv47.xml");
    AlgorithmConfig config = AlgorithmConfig();
    config.population_size = 1000;
    config.crossover_rate = 0.8;
    config.mutation_rate = 0.01;
    config.stopping_condition = 2 * 60;
    config.elitism_percentage = 0.001;
    config.number_of_elites = 2;

    GeneticAlgorithm ga = GeneticAlgorithm(config);

    auto result = ga.process(graph);
    cout << "Path cost: " << result.path_cost << endl;

    for (auto city : result.tour ) {
        cout << city << " ";
    }
    cout << endl;

    FileWriter::write_to_file("test", result.tour);
}

//Chromosome first_offspring;
//Chromosome second_offspring;
//
//Chromosome p1 = Chromosome();
//p1.tour = {1, 2, 3, 4, 5, 6, 7, 8 ,9};
//
//Chromosome p2 = Chromosome();
//p2.tour = {4 ,5, 2, 1, 8, 7, 6, 9, 3};