// Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

// Example:
// Given a / b = 2.0, b / c = 3.0. 
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].

// The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

// According to the example above:

// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

double dfs(unordered_map<string, vector<pair<string, double>>> &graph, const string &cur, const string &dest, unordered_set<string> &visited) {
    visited.insert(cur);
    if (cur == dest) {
        return 1;
    }
    for (auto p = graph[cur].begin(); p != graph[cur].end(); ++p) {
        if (visited.find(p->first) != visited.end())
            continue;
        double value = dfs(graph, p->first, dest, visited);
        if (value + 1.0 > 0.000001) {
            return  p->second * value;
        }
    }
    return -1;
}

vector<double> CalcEquation(const vector<pair<string, string>> &equations, const vector<double> &values, const vector<pair<string, string>> &queries) {
    if (equations.size() != values.size() || equations.empty() || values.empty() || queries.empty())
        return vector<double>();
    vector<double> results;
    unordered_map<string, vector<pair<string, double>>> graph;
    for (int i = 0; i < equations.size(); ++i) {
        graph[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
        graph[equations[i].second].push_back(make_pair(equations[i].first, 1 / values[i]));
    }
    for (int i = 0; i < queries.size(); ++i) {
        if (queries[i].first == queries[i].second) {
            results.push_back(graph.find(queries[i].first) == graph.end() ? -1.0 : 1.0);
        } else {
            unordered_set<string> visited;
            results.push_back(dfs(graph, queries[i].first, queries[i].second, visited));
        }
    }
    return results;
}
