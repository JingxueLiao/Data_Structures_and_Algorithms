// For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// Example 1:

// Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        // 0
        // |
        // 1
       // / \
      // 2   3
// return [1]

// Example 2:

// Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     // 0  1  2
      // \ | /
        // 3
        // |
        // 4
        // |
        // 5
// return [3, 4]

#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> FindMinHeightTrees(int n, vector<pair<int, int>> &edges) {
    if (n <= 0)
        return vector<int>();
    if (n == 1)
        return vector<int>{0};
    vector<vector<int>> graph(n);
    vector<int> degrees(n);
    for (auto p = edges.begin(); p != edges.end(); ++p) {
        graph[p->first].push_back(p->second);
        ++degrees[p->first];
        graph[p->second].push_back(p->first);
        ++degrees[p->second];
    }
    vector<int> level;
    int left = n;
    for (int i = 0; i < n; ++i) {
        if (degrees[i] == 1) {
            level.push_back(i);
            --left;
        }
    }
    while (left) {
        vector<int> next;
        for (auto p = level.begin(); p != level.end(); ++p) {
            for (auto q = graph[*p].begin(); q != graph[*p].end(); ++q) {
                if (--degrees[*q] == 1) {
                    next.push_back(*q);
                }
            }
        }
        level = move(next);
        left -= level.size();
    }
    return level;
}
