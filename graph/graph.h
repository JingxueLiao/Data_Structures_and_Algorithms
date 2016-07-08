#pragma once

#include <vector>

using std::vector;

vector<int> breadth_first_search(const vector<vector<int>> &graph);
vector<int> depth_first_search(const vector<vector<int>> &graph);
bool is_acyclic(const vector<vector<int>> &graph);
vector<int> topological_sort(const vector<vector<int>> &graph);
vector<vector<int>> strongly_connected_components(const vector<vector<int>> &graph);
