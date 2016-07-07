#pragma once

#include <vector>

using std::vector;

void dfs(const vector<vector<int>> &graph, vector<bool> &visited, int cur, vector<int> &result) {
    visited[cur] = true;
    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
        if (!visited[*p]) {
            dfs(graph, visited, *p, result);
        }
    }
    result.push_back(cur);
}

vector<vector<int>> strongly_connected_components(const vector<vector<int>> &graph) {
    vector<int> traverse;
    vector<bool> visited(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            dfs(graph, visited, i, traverse);
        }
    }
    vector<vector<int>> reverse_graph(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        for (auto p = graph[i].begin(); p != graph[i].end(); ++p) {
            reverse_graph[*p].push_back(i);
        }
    }
    vector<vector<int>> components;
    for (int i = 0; i < visited.size(); ++i) {
        visited[i] = false;
    }
    for (auto p = traverse.rbegin(); p != traverse.rend(); ++p) {
        if (!visited[*p]) {
            components.push_back(vector<int>());
            dfs(reverse_graph, visited, *p, components.back());
        }
    }
    return components;
}
