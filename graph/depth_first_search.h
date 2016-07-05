#pragma once

#include <vector>

using std::vector;

void depth_first_search_helper(const vector<vector<int>> &graph, vector<char> &colors, int cur) {
    colors[cur] = 'g';
    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
        if (colors[*p] == 'w') {
            depth_first_search_helper(graph, colors, *p);
        }
    }
    colors[cur] = 'b';
}

void depth_first_search(const vector<vector<int>> &graph) {
    vector<char> colors(graph.size(), 'w');
    for (int i = 0; i < graph.size(); ++i) {
        if (colors[i] == 'w') {
            depth_first_search_helper(graph, colors, i);
        }
    }
}
