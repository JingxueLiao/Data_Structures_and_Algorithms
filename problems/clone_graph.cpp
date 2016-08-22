// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) { }
};

UndirectedGraphNode *CloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr)
        return nullptr;
    UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
    queue<pair<UndirectedGraphNode *, UndirectedGraphNode *>> level;
    level.push(make_pair(node, clone));
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> node_map;
    node_map[node] = clone;
    while (!level.empty()) {
        node = level.front().first;
        UndirectedGraphNode *cur = level.front().second;
        level.pop();
        for (auto p = node->neighbors.begin(); p != node->neighbors.end(); ++p) {
            if (node_map.find(*p) == node_map.end()) {
                node_map[*p] = new UndirectedGraphNode((*p)->label);
                level.push(make_pair(*p, node_map[*p]));
            }
            cur->neighbors.push_back(node_map[*p]);
        }
    }
    return clone;
}
