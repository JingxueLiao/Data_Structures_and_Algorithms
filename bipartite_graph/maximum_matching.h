#pragma once

#include <vector>

using std::vector;

bool find_path(const vector<vector<int>> &graph, vector<int> &pairs, vector<bool> &visited, int cur) {
    if (visited[cur])
        return false;
    visited[cur] = true;
    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
        if (pairs[*p] == -1 || find_path(graph, pairs, visited, pairs[*p])) {
            pairs[cur] = *p;
            pairs[*p] = cur;
            return true;
        }
    }
    return false;
}

int maximum_matching(const vector<vector<int>> &graph) {
    vector<int> pairs(graph.size(), -1);
    int matching = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (pairs[i] != -1)
            continue;
        vector<bool> visited(graph.size());
        if (find_path(graph, pairs, visited, i))
            ++matching;
    }
    return matching;
}
