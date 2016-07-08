#include <vector>
#include <queue>

using std::vector;
using std::queue;

vector<int> breadth_first_search(const vector<vector<int>> &graph) {
    vector<int> traverse;
    vector<char> colors(graph.size(), 'w');
    queue<int> path;
    for (int i = 0; i < graph.size(); ++i) {
        if (colors[i] == 'w') {
            path.push(i);
            colors[i] = 'g';
            while (!path.empty()) {
                int cur = path.front();
                path.pop();
                traverse.push_back(cur);
                for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
                    if (colors[*p] == 'w') {
                        path.push(*p);
                        colors[*p] = 'g';
                    }
                }
                colors[cur] = 'b';
            }
        }
    }
    return traverse;
}
