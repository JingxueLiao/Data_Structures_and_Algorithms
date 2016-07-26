// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and set.
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) { }

    int get(int key) {
        auto p = caches.find(key);
        if (p == caches.end())
            return -1;
        histories.push_front(*p->second);
        histories.erase(p->second);
        p->second = histories.begin();
        return histories.front().second;
    }

    void set(int key, int value) {
        auto p = caches.find(key);
        if (p != caches.end()) {
            histories.erase(p->second);
        } else {
            if (histories.size() == capacity_) {
                caches.erase(histories.back().first);
                histories.pop_back();
            }
        }
        histories.push_front(make_pair(key, value));
        caches[key] = histories.begin();
    }

private:
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> caches;
    list<pair<int, int>> histories;
};
