#include "Menu.h"
#include "../model/Graph.h"
#include "../file/FileReader.h"
#include "Utils.h"
#include "../algorithm/model/AlgorithmConfig.h"
#include "../algorithm/GeneticAlgorithm.h"
#include <iostream>

using namespace std;

void menu::create_menu() {
    int choice;
    Graph graph;
    AlgorithmConfig config;
    vector<int> solution;

    string buffer;

    while (true) {
        utils::clear_console();
        print_options();
        choice = utils::get_input();
        utils::clear_console();
        switch (choice) {
            case 1: {
                cout << "Enter file path: ";
                cin >> buffer;
                graph = FileReader::read_graph_from_xml_file(buffer);

                if (graph.is_empty()) {
                    cout << "Reading from file was unsuccessful. Please try again..." << endl;
                    utils::press_key_to_continue();
                }
                break;
            }
            case 2: {
                if (graph.is_empty()) {
                    cout << "Operation unsuccessful. Read problem from file first." << endl;
                    utils::press_key_to_continue();
                    break;
                }
                cout << "Problem visualisation as a adjacency matrix implementation of a finite graph" << endl << endl;
                graph.print();
                utils::press_key_to_continue();
                break;
            }
            case 3: {
                cout << "Enter stopping condition (time limit in seconds): ";
                config.stopping_condition = utils::get_input();
                break;
            }
            case 4: {
                cout << "Enter initial population size: ";
                cin >> buffer;
                config.population_size = stoi(buffer);
                break;
            }
            case 5: {
                cout << "Enter coefficient of mutation (should be between 0.0 and 1.0): ";
                cin >> buffer;
                config.mutation_rate = stof(buffer);
                break;
            }
            case 6: {
                cout << "Enter coefficient of crossover (should be between 0.0 and 1.0): ";
                cin >> buffer;
                config.crossover_rate = stof(buffer);
                break;
            }
            case 7: {
                if (graph.is_empty()) {
                    cout << "Operation unsuccessful. Read problem from file first." << endl;
                    utils::press_key_to_continue();
                    break;
                }

                cout << "Genetic Algorithm" << endl;
                GeneticAlgorithm geneticAlgorithm = GeneticAlgorithm{config};
                geneticAlgorithm.process(graph);

                // TODO: print Result
//                solution = result.best_path;
//                print_result(result.greedy_cost, result.best_cost, result.best_path);
                utils::press_key_to_continue();
                break;
            }
            case 8: {
                cout << "Choose crossover type: ";
                cout << "1. PARTIALLY MAPPED CROSSOVER" << endl;
                cout << "2. PARTITION CROSSOVER" << endl;
                cin >> buffer;

                choice = std::stoi(buffer);
                if (crossover_map.find(choice) != crossover_map.end()) {
                    config.crossover_type = crossover_map[choice];
                    break;
                }
                std::cerr << "Invalid input" << std::endl;
                break;
            }
            case 9: {
                cout << "Choose mutation type: ";
                cout << "1. DISPLACEMENT MUTATION" << endl;
                cout << "2. INSERTION MUTATION" << endl;
                cin >> buffer;

                choice = std::stoi(buffer);
                if (mutation_map.find(choice) != mutation_map.end()) {
                    config.mutation_type = mutation_map[choice];
                    break;
                }
                std::cerr << "Invalid input" << std::endl;
                break;
            }
            case 10: {
                cout << "Quitting application..." << endl;
                exit(0);
            }
            default: {
                break;
            }
        }
    }
}

void menu::print_options() {
    cout << endl;
    cout << "================================" << std::endl;
    cout << "Travelling Salesman Problem Menu" << std::endl;
    cout << "================================ " << std::endl;
    cout << "1. Read from XML file" << std::endl;
    cout << "2. Display problem as adjacency matrix graph representation" << std::endl;
    cout << "3. Enter time limit (time stopping condition)" << std::endl;
    cout << "4. Set population size" << std::endl;
    cout << "5. Set mutation coefficient" << std::endl;
    cout << "6. Set crossover coefficient" << std::endl;
    cout << "7. Run Genetic Algorithm" << std::endl;
    cout << "8. Choose crossover method" << std::endl;
    cout << "9. Choose mutation method" << std::endl;
    cout << "10. Exit" << std::endl;
    cout << "Choose: ";
}

void menu::print_result(int greedy_result, int algorithm_result, const vector<int>& path) {
    cout << "----results----" << endl;
    cout << "Greedy result: " << greedy_result << endl;
    cout << "Final result: " << algorithm_result << endl;
    cout << "Path: ";
    for (auto city: path) {
        cout << city << " ";
    }
    cout << endl;
}
