#pragma once

#include <vector>

using std::vector;

void dfs(const vector<vector<int>> &graph, vector<bool> &visited, int cur, vector<int> &sorted, int &index) {
    visited[cur] = true;
    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
        if (!visited[*p]) {
            dfs(graph, visited, *p, sorted, index);
        }
    }
    sorted[--index] = cur;
}

vector<int> topological_sort(const vector<vector<int>> &graph) {
    vector<int> sorted(graph.size());
    vector<bool> visited(graph.size());
    int index = sorted.size();
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            dfs(graph, visited, i, sorted, index);
        }
    }
    return sorted;
}
