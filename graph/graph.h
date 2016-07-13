#pragma once

#include <vector>

using std::vector;

vector<int> breadth_first_search(const vector<vector<int>> &graph);
vector<int> depth_first_search(const vector<vector<int>> &graph);
bool is_acyclic(const vector<vector<int>> &graph);
vector<int> topological_sort(const vector<vector<int>> &graph);
vector<vector<int>> strongly_connected_components(const vector<vector<int>> &graph);
bool is_euler_path(const vector<vector<int>> &graph, bool directed);
vector<int> euler_path_undirected_graph(const vector<vector<int>> &graph);
vector<int> euler_path_directed_graph(const vector<vector<int>> &graph);
