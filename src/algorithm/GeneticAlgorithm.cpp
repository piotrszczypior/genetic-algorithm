#include <chrono>
#include <random>
#include <unordered_map>
#include <utility>
#include "GeneticAlgorithm.h"
#include "factory/CrossoverProducerFactory.h"
#include "factory/MutationProducerFactory.h"

GeneticAlgorithm::GeneticAlgorithm(AlgorithmConfig config) {
    this->config = config;
    crossoverProducer = CrossoverProducerFactory().get(config.crossover_type);
    mutationProducer = MutationProducerFactory().get(config.mutation_type);
}

Result GeneticAlgorithm::process(const Graph &graph) {
    this->graph = graph;
    std::vector<Chromosome> population = initialize_population();

    auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration(config.stopping_condition);
    evaluate_population(population);

    while (std::chrono::high_resolution_clock::now() - start_time < duration) {

        vector<Chromosome> children;
        for (int i = 0; i < static_cast<int>(config.population_size * config.crossover_rate); ++i) {
            int first_index = std::uniform_int_distribution<int>(0, config.population_size - 1)(generator);
            int second_index = std::uniform_int_distribution<int>(0, config.population_size - 1)(generator);

            while (first_index == second_index) {
                second_index = std::uniform_int_distribution<int>(0, config.population_size - 1)(generator);
            }
            auto offsprings = crossoverProducer->crossover(graph.get_city_number(),
                                                           population[first_index],
                                                           population[second_index]);
            evaluate_chromosomes(offsprings);
            population.push_back(offsprings.first);
            population.push_back(offsprings.second);
        }

        for (int i = 0; i < static_cast<int>(config.population_size * config.mutation_rate); ++i) {
            int random_index = std::uniform_int_distribution<int>(0, population.size() - 1)(generator);
            mutationProducer->mutate(graph.get_city_number(), population[random_index]);
            evaluate_chromosome(population[random_index]);
        }

        population = tournament_selection(population);
        auto fittest_chromosome = min_element(population.begin(), population.end(), compare_chromosomes);
        if (fittest_chromosome->fitness < result.path_cost) {
            result.path_cost = fittest_chromosome->fitness;
            result.tour = fittest_chromosome->tour;
//            cout << result.path_cost << endl;

            auto measure_time =
                    std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start_time).count();
            result.measurements.emplace_back(measure_time, result.path_cost);
        }
    }
    delete crossoverProducer;
    delete mutationProducer;
    return result;
}

std::vector<Chromosome> GeneticAlgorithm::initialize_population() {
    std::vector<Chromosome> population;
    population.reserve(config.population_size);

    int city_number = graph.get_city_number();
    vector<int> base_path(city_number + 1);
    iota(base_path.begin(), base_path.end() - 1, 0);
    base_path.back() = 0;

    for (int i = 0; i < config.population_size; ++i) {
        std::shuffle(base_path.begin() + 1, base_path.end() - 1, generator);

        Chromosome new_chromosome;
        new_chromosome.tour = base_path;
        population.push_back(new_chromosome);
    }

    return population;
}


std::vector<Chromosome> GeneticAlgorithm::tournament_selection(const std::vector<Chromosome> &population) {
    std::vector<Chromosome> new_population;
    int tournament_size = int(graph.get_city_number() * 0.05);
    auto best = *std::min_element(population.begin(), population.end(), compare_chromosomes);
    // TODO:
//    std::remove(population.begin(), population.end(), best);
    auto distribution = std::uniform_int_distribution<int>(0, int(population.size()) - 1);

    while (new_population.size() < config.population_size - 1) {
        std::vector<Chromosome> tournament;

        for (int i = 0; i < tournament_size; ++i) {
            int random_index = distribution(generator);
            tournament.push_back(population[random_index]);
        }

        Chromosome strongest_individual = *std::min_element(tournament.begin(),
                                                            tournament.end(),
                                                            compare_chromosomes);
        new_population.push_back(strongest_individual);
    }
    new_population.push_back(best);

    return new_population;
}

int GeneticAlgorithm::calculate_fitness(const Chromosome &chromosome) {
    int cost = 0;
    for (int i = 0; i < graph.get_city_number(); ++i) {
        cost += graph.get_edge_cost_if_exists(chromosome.tour[i], chromosome.tour[i + 1]);
    }
    return cost;
}

void GeneticAlgorithm::evaluate_population(std::vector<Chromosome> &population) {
    for (auto &chromosome: population) {
        chromosome.fitness = calculate_fitness(chromosome);
    }
}

vector<Chromosome> GeneticAlgorithm::select_elite_individuals(const vector<Chromosome> &population) {
    std::vector<Chromosome> elites;
    elites.reserve(config.number_of_elites);

    std::vector<Chromosome> sorted_population = population;
    std::sort(sorted_population.begin(), sorted_population.end(), compare_chromosomes);

    for (int i = 0; i < config.number_of_elites; ++i) {
        elites.push_back(sorted_population[i]);
    }
    return elites;
}

void GeneticAlgorithm::evaluate_chromosome(Chromosome &chromosome) {
    int fitness = calculate_fitness(chromosome);
    chromosome.fitness = fitness;
}

void GeneticAlgorithm::evaluate_chromosomes(pair<Chromosome, Chromosome> &chromosomes) {
    evaluate_chromosome(chromosomes.first);
    evaluate_chromosome(chromosomes.second);
}
