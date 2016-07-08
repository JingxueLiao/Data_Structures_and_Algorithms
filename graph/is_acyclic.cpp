#include <vector>

using std::vector;

bool is_acyclic_helper(const vector<vector<int>> &graph, vector<char> &colors, int cur) {
    colors[cur] = 'g';
    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
        if (colors[*p] == 'w') {
            if (!is_acyclic_helper(graph, colors, *p))
                return false;
        } else if (colors[*p] == 'g') {
            return false;
        }
    }
    colors[cur] = 'b';
    return true;
}

bool is_acyclic(const vector<vector<int>> &graph) {
    vector<char> colors(graph.size(), 'w');
    for (int i = 0; i < graph.size(); ++i)
        if (colors[i] == 'w' && !is_acyclic_helper(graph, colors, i))
            return false;
    return true;
}

/*

#include <queue>

using std::queue;

bool is_acyclic(const vector<vector<int>> &graph) {
    vector<int> indegrees(graph.size());
    for (auto p = graph.begin(); p != graph.end(); ++p)
        for (auto q = p->begin(); q != p->end(); ++q)
            ++indegrees[*q];
    queue<int> candidates;
    for (int i = 0; i < indegrees.size(); ++i)
        if (indegrees[i] == 0)
            candidates.push(i);
    int chosen = 0;
    while (!candidates.empty()) {
        int cur = candidates.front();
        candidates.pop();
        ++chosen;
        for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p)
            if (--indegrees[*p] == 0)
                candidates.push(*p);
    }
    return chosen == graph.size();
}

*/
