#include <vector>

using std::vector;

bool is_euler_path_directed_graph(const vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> indegrees(n), outdegrees(n);
    for (int i = 0; i < n; ++i) {
        outdegrees[i] = graph[i].size();
        for (auto p = graph[i].begin(); p != graph[i].end(); ++p) {
            ++indegrees[*p];
        }
    }
    bool start = false, end = false;
    for (int i = 0; i < n; ++i) {
        if (indegrees[i] == outdegrees[i]) {
            continue;
        } else if (indegrees[i] + 1 == outdegrees[i]) {
            if (start)
                return false;
            start = true;
        } else if (outdegrees[i] + 1 == indegrees[i]) {
            if (end)
                return false;
            end = true;
        } else {
            return false;
        }
    }
    return false;
}

bool is_euler_path_undirected_graph(const vector<vector<int>> &graph) {
    int odd = 0;
    for (auto p = graph.begin(); p != graph.end(); ++p)
        if (p->size() % 2)
            ++odd;
    return odd == 0 || odd == 2;
}

bool is_euler_path(const vector<vector<int>> &graph, bool directed) {
    return directed ? is_euler_path_directed_graph(graph) : is_euler_path_undirected_graph(graph);
}

void euler_path_undirected_graph_helper(vector<vector<int>> &graph, int cur, vector<int> &path) {
    while (!graph[cur].empty()) {
        int next = graph[cur].back();
        graph[cur].pop_back();
        for (auto p = graph[next].begin(); p != graph[next].end(); ++p) {
            if (*p == cur) {
                *p = graph[next].back();
                graph[next].pop_back();
                break;
            }
        }
        euler_path_undirected_graph_helper(graph, next, path);
    }
    path.push_back(cur);
    return;
}

vector<int> euler_path_undirected_graph(const vector<vector<int>> &graph) {
    vector<int> path;
    vector<vector<int>> tmp(graph);
    int start = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[i].size() % 2) {
            start = i;
            break;
        }
    }
    euler_path_undirected_graph_helper(tmp, start, path);
    return path;
}

void euler_path_directed_graph_helper(vector<vector<int>> &graph, int cur, vector<int> &path) {
    while (!graph[cur].empty()) {
        int next = graph[cur].back();
        graph[cur].pop_back();
        euler_path_directed_graph_helper(graph, next, path);
    }
    path.push_back(cur);
    return;
}

vector<int> euler_path_directed_graph(const vector<vector<int>> &graph) {
    vector<int> path;
    vector<vector<int>> tmp(graph);
    vector<int> indegrees(graph.size()), outdegrees(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        outdegrees[i] = graph[i].size();
        for (auto p = graph[i].begin(); p != graph[i].end(); ++p)
            ++indegrees[*p];
    }
    int start = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (indegrees[i] + 1 == outdegrees[i]) {
            start = i;
            break;
        }
    }
    euler_path_directed_graph_helper(tmp, start, path);
    return vector<int>(path.rbegin(), path.rend());
}
