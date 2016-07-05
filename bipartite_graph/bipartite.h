#pragma once

#include <vector>

using std::vector;

bool dfs(const vector<vector<int>> &graph, vector<bool> &color, vector<bool> &visited, int cur) {
    visited[cur] = true;
    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
        if (visited[*p]) {
            if (color[*p] == color[cur])
                return false;
        } else {
            color[*p] = !color[cur];
            if (!dfs(graph, color, visited, *p))
                return false;
        }
    }
    return true;
}

bool bipartite(const vector<vector<int>> &graph) {
    vector<bool> color(graph.size()), visited(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        if (visited[i])
            continue;
        if (!dfs(graph, color, visited, i))
            return false;
    }
    return true;
}
