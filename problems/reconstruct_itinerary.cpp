// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order.
// All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

// Note:
// 1. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// 2. All airports are represented by three capital letters (IATA code).
// 3. You may assume all tickets form at least one valid itinerary.

// Example 1:
// tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

// Example 2:
// tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
// Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <set>

using namespace std;

void dfs(unordered_map<string, multiset<string>> &graph, string cur, vector<string> &itinerary) {
    multiset<string> &next_cities = graph[cur];
    while (!next_cities.empty()) {
        string next = *next_cities.begin();
        next_cities.erase(next_cities.begin());
        dfs(graph, next, itinerary);
    }
    itinerary.push_back(cur);
}

vector<string> FindItinerary(const vector<pair<string, string>> &tickets) {
    if (tickets.empty())
        return vector<string>();
    unordered_map<string, multiset<string>> graph;
    for (auto p = tickets.begin(); p != tickets.end(); ++p)
        graph[p->first].insert(p->second);
    vector<string> itinerary;
    dfs(graph, "JFK", itinerary);
    return vector<string>(itinerary.rbegin(), itinerary.rend());
}
