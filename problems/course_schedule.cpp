// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1].
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices.

#include <vector>
#include <utility>

using namespace std;

bool ExistCycle(const vector<vector<int>> &graph, vector<char> &colors, int cur) {
    colors[cur] = 'g';
    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p)
        if (colors[*p] == 'g' || colors[*p] == 'w' && ExistCycle(graph, colors, *p))
            return true;
    colors[cur] = 'b';
    return false;
}

bool CanFinish(int numCourses, const vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto p = prerequisites.begin(); p != prerequisites.end(); ++p)
        graph[p->second].push_back(p->first);
    vector<char> colors(numCourses, 'w');
    for (int i = 0; i < numCourses; ++i) {
        if (colors[i] == 'w' && ExistCycle(graph, colors, i))
            return false;
    }
    return true;
}
