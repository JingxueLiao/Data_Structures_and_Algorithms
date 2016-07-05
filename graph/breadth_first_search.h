#pragma once

#include <vector>
#include <queue>

using std::vector;
using std::queue;

void breadth_first_search(const vector<vector<int>> &graph) {
    vector<bool> visited(graph.size());
    queue<int> path;
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            path.push(i);
            visited[i] = true;
            while (!path.empty()) {
                int cur = path.front();
                path.pop();
                for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
                    if (!visited[*p]) {
                        path.push(*p);
                        visited[*p] = true;
                    }
                }
            }
        }
    }
}
