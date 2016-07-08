#include <vector>

using std::vector;

void topological_sort_helper(const vector<vector<int>> &graph, vector<bool> &visited, int cur, vector<int> &sorted, int &index) {
    visited[cur] = true;
    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p)
        if (!visited[*p])
            topological_sort_helper(graph, visited, *p, sorted, index);
    sorted[--index] = cur;
}

vector<int> topological_sort(const vector<vector<int>> &graph) {
    vector<int> sorted(graph.size());
    vector<bool> visited(graph.size());
    int index = sorted.size();
    for (int i = 0; i < graph.size(); ++i)
        if (!visited[i])
            topological_sort_helper(graph, visited, i, sorted, index);
    return sorted;
}

/*

#include <queue>

using std::queue;

vector<int> topological_sort(const vector<vector<int>> &graph) {
    vector<int> sorted;
    vector<int> indegrees(graph.size());
    for (auto p = graph.begin(); p != graph.end(); ++p)
        for (auto q = p->begin(); q != p->end(); ++q)
            ++indegrees[*q];
    queue<int> candidates;
    for (int i = 0; i < indegrees.size(); ++i)
        if (indegrees[i] == 0)
            candidates.push(i);
    while (!candidates.empty()) {
        int cur = candidates.front();
        candidates.pop();
        sorted.push_back(cur);
        for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p)
            if (--indegrees[*p] == 0)
                candidates.push(*p);
    }
    return sorted;
}

*/
