#include <iostream>
#include "algorithm/GeneticAlgorithm.h"
#include "file/FileReader.h"
#include "file-writer/FileWriter.h"
#include "algorithm/crossover/OrderedCrossoverProducer.h"
#include "algorithm/factory/CrossoverProducerFactory.h"
#include "algorithm/mutation/ScrambleMutationProducer.h"

using namespace std;

CrossoverType get_crossover_type(string type) {
    if (type == "PARTIALLY_MAPPED_CROSSOVER")
        return CrossoverType::PARTIALLY_MAPPED_CROSSOVER;
    return CrossoverType::ORDERED_CROSSOVER;
}

MutationType get_mutation_type(string type) {
    if (type == "DISPLACEMENT_MUTATION")
        return MutationType::DISPLACEMENT_MUTATION;
    return MutationType::SCRAMBLE_MUTATION;
}

bool check(string method) {
    return method == "crossover";
}

void test(char *argv[]) {
    auto graph = FileReader::read_graph_from_xml_file(argv[1]);
    AlgorithmConfig config = AlgorithmConfig();
    config.stopping_condition = stoi(argv[2]);
    config.population_size = stoi(argv[3]);
    config.crossover_type = get_crossover_type(argv[4]);
    config.mutation_type = get_mutation_type(argv[5]);

    if(check(argv[7])) {
        config.crossover_rate = stof(argv[6]);
        config.mutation_rate = 0.01;
    } else {
        config.mutation_rate = stof(argv[6]);
        config.crossover_rate = 0.8;
    }

    GeneticAlgorithm ga = GeneticAlgorithm(config);
    auto result = ga.process(graph);
    cout << result.path_cost << ",[";
    for (auto measure: result.measurements) {
        cout << "(" << measure.first << "," << measure.second << "),";
    }
    cout << "]";
    FileWriter::write_to_file(argv[8],result.path_cost,result.tour);
}



int main(int argc, char *argv[]) {
    auto graph = FileReader::read_graph_from_xml_file("../data/ftv170.xml");
    AlgorithmConfig config = AlgorithmConfig();
    config.crossover_rate = 0.8;
    config.mutation_rate = 0.01;
    config.stopping_condition = 240;
    config.population_size = 5000;
    config.crossover_type = CrossoverType::ORDERED_CROSSOVER;
    config.mutation_type = MutationType::SCRAMBLE_MUTATION;
    GeneticAlgorithm ga = GeneticAlgorithm(config);
    auto result = ga.process(graph);
    cout << result.path_cost << endl;
}




//Chromosome first_offspring;
//Chromosome second_offspring;
//
//Chromosome p1 = Chromosome();
//p1.tour = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//
//Chromosome p2 = Chromosome();
//p2.tour = {0, 4, 5, 2, 1, 8, 7, 6, 9, 3, 0};
//ScrambleMutationProducer producer;
//producer.mutate(p2.tour.size() - 1, p2);
//for (int i = 0; i < p2.tour.size(); ++i) {
//cout << p2.tour[i] << " ";
//}
//
//

//
