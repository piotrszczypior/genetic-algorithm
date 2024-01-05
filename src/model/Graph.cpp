#include <iomanip>
#include "Graph.h"

Graph::Graph() {
    this->city_number = 0;
}

Graph::Graph(const vector<vector<int>>& matrix) {
    this->graph = matrix;
    this->city_number = matrix.size();
}

Graph::Graph(int city_number) {
    this->city_number = city_number;
    graph.resize(city_number, vector<int>(city_number));
}

void Graph::add_new_connection(int source_city, int destination_city, int cost) {
    if (source_city >= city_number || destination_city >= city_number) {
        return;
    }
    this->graph[source_city][destination_city] = cost;
}

vector<int> &Graph::get_adjacent_cities(int city) {
    return graph[city];
}

int Graph::get_city_number() const {
    return city_number;
}

bool Graph::find_adjacent_city(int from_city, int to_city) {
    auto adjacent_cities = graph[from_city];
    return adjacent_cities[to_city] != -1;
}

int Graph::get_edge_cost_if_exists(int from_city, int to_city) {
    auto adjacent_cities = graph[from_city];

    if(adjacent_cities[to_city] == -1) {
        return INT_MAX;
    }
    return adjacent_cities[to_city];
}

bool Graph::is_empty() {
    return this->graph.empty();
}

void Graph::print() {
    for (int i = 0; i < city_number ; ++i) {
        for (int j = 0; j < city_number; ++j) {
            cout << setw(4) << graph[i][j] << " ";
        }
        cout << endl;
    }
}