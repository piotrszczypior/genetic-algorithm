#ifndef TRAVELLING_SALESMAN_PROBLEM_GRAPH_H
#define TRAVELLING_SALESMAN_PROBLEM_GRAPH_H

#include <vector>
#include <iostream>

using namespace std;

class Graph {
private:
    int city_number = 0;
    vector<vector<int>> graph;

public:
    Graph();

    explicit Graph(int city_number);

    explicit Graph(const vector<vector<int>>& matrix);

    void print();

    void add_new_connection(int from, int to, int cost);

    vector<int> &get_adjacent_cities(int city);

    bool find_adjacent_city(int from_city, int to_city);

    bool is_empty();

    int get_edge_cost_if_exists(int from_city, int to_city);

    int get_city_number() const;

    const vector<vector<int>> &get_graph_as_vector() const {
        return graph;
    }
};


#endif //TRAVELLING_SALESMAN_PROBLEM_GRAPH_H
