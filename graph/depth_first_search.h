#pragma once

#include <vector>
#include <stack>

using std::vector;
using std::stack;

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

void depth_first_search_iterator(const vector<vector<int>> &graph) {
    vector<char> colors(graph.size(), 'w');
    stack<int> path;
    for (int i = 0; i < graph.size(); ++i) {
        if (colors[i] == 'w') {
            path.push(i);
            while (!path.empty()) {
                int cur = path.top();
                if (colors[cur] == 'w') {
                    colors[cur] = 'g';
                    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
                        if (colors[*p] == 'w') {
                            path.push(*p);
                        }
                    }
                } else if (colors[cur] == 'g') {
                    colors[cur] = 'b';
                    path.pop();
                } else if (colors[cur] == 'b') {
                    path.pop();
                }
            }
        }
    }
}
