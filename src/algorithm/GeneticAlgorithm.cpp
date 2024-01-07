#include <chrono>
#include <random>
#include <unordered_map>
#include "GeneticAlgorithm.h"

// TODO: parametrize Mutation method and Crossover method
GeneticAlgorithm::GeneticAlgorithm(AlgorithmConfig config) {
    this->config = config;
}

Result GeneticAlgorithm::process(const Graph &graph) {
    this->graph = graph;
    std::vector<Chromosome> population = initialize_population();

    auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration(config.stopping_condition);

    while (std::chrono::high_resolution_clock::now() - start_time < duration) {
        evaluate_population(population);
        auto fittest_chromosome = min_element(population.begin(), population.end(), compare_chromosomes);
        if (fittest_chromosome->fitness < result.path_cost) {
            result.path_cost = fittest_chromosome->fitness;
            result.tour = fittest_chromosome->tour;
//            cout << "New best " << fittest_chromosome->fitness << endl;
        }
        population = tournament_selection(population);

        // TODO: use crossover and mutation based on rate parameters
        for (size_t i = 0; i < population.size(); i += 2) {
            double random_value = std::uniform_real_distribution<double>(0.0, 1.0)(generator);
            if (random_value < config.crossover_rate && i + 1 < population.size()) {
                auto offsprings = crossover(population[i], population[i + 1]);
                population[i] = offsprings.first;
                population[i + 1] = offsprings.second;
            }
        }

        for (Chromosome &chromosome: population) {
            double random_value = std::uniform_real_distribution<double>(0.0, 1.0)(generator);
            if (random_value < config.mutation_rate) {
                mutate(chromosome);
            }
        }
    }
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
        // TODO: see possible improvement in initialization of population if each shuffle is made on the same path
        std::shuffle(base_path.begin() + 1, base_path.end() - 1, generator);

        Chromosome new_chromosome;
        new_chromosome.tour = base_path;
        population.push_back(new_chromosome);
    }

    return population;
}


std::vector<Chromosome> GeneticAlgorithm::tournament_selection(const std::vector<Chromosome> &population) {
    std::vector<Chromosome> selected_parents;
    int tournament_size = int(graph.get_city_number() * 0.05);
    Chromosome best = *std::min_element(population.begin(), population.end(), compare_chromosomes);

    while (selected_parents.size() < config.population_size - 1) {
        std::vector<Chromosome> tournament;

        for (int i = 0; i < tournament_size; ++i) {
            int randomIndex = std::uniform_int_distribution<int>(0, int(population.size()) - 1)(generator);
            tournament.push_back(population[randomIndex]);
        }

        Chromosome fittest = *std::min_element(tournament.begin(), tournament.end(), compare_chromosomes);
        selected_parents.push_back(fittest);
    }
    selected_parents.push_back(best);

    return selected_parents;
}

int GeneticAlgorithm::calculate_fitness(const Chromosome &chromosome) {
    int cost = 0;
    for (int i = 0; i < graph.get_city_number(); ++i) {
        cost += graph.get_edge_cost_if_exists(chromosome.tour[i], chromosome.tour[i + 1]);
    }
    return cost;
}

void GeneticAlgorithm::mutate(Chromosome &chromosome) {
    int problem_size = graph.get_city_number();

    int start = uniform_int_distribution<int>(1, problem_size - 3)(generator);
    int end = uniform_int_distribution<int>(start + 1, problem_size - 1)(generator);

    std::vector<int> subsequence(chromosome.tour.begin() + start, chromosome.tour.begin() + end);

    chromosome.tour.erase(chromosome.tour.begin() + start, chromosome.tour.begin() + end);

    int insertionPoint = std::uniform_int_distribution<int>(1, problem_size - int(subsequence.size()) - 1)(generator);

    chromosome.tour.insert(chromosome.tour.begin() + insertionPoint, subsequence.begin(), subsequence.end());
}

// TODO: make pairs as arguments and return pair?
pair<Chromosome, Chromosome>
GeneticAlgorithm::crossover(const Chromosome &first_chromosome, const Chromosome &second_chromosome) {
    Chromosome first_offspring;
    Chromosome second_offspring;

    int city_number = graph.get_city_number();

    int first_crossover_point = uniform_int_distribution<int>(1, city_number - 3)(generator);
    int second_crossover_point = uniform_int_distribution<int>(first_crossover_point + 1, city_number - 1)(generator);

    first_offspring.tour = first_chromosome.tour;
    second_offspring.tour = second_chromosome.tour;

    for (int i = first_crossover_point; i <= second_crossover_point; ++i) {
        std::swap(first_offspring.tour[i], second_offspring.tour[i]);
    }

    const auto repair =
            [&](Chromosome &offspring, const Chromosome &first_parent, const Chromosome &second_parent) {
                std::unordered_map<int, int> mapping;
                for (int i = first_crossover_point; i <= second_crossover_point; ++i) {
                    mapping[first_parent.tour[i]] = second_parent.tour[i];
                }

                for (int i = 1; i < city_number; ++i) {
                    if (i >= first_crossover_point && i <= second_crossover_point) {
                        continue;
                    }

                    while (mapping.find(offspring.tour[i]) != mapping.end()) {
                        offspring.tour[i] = mapping[offspring.tour[i]];
                    }
                }
            };

    repair(first_offspring, second_chromosome, first_chromosome);
    repair(second_offspring, first_chromosome, second_chromosome);
    return make_pair(first_offspring, second_offspring);
}

void GeneticAlgorithm::evaluate_population(std::vector<Chromosome> &population) {
    for (auto &chromosome: population) {
        chromosome.fitness = calculate_fitness(chromosome);
    }
}


