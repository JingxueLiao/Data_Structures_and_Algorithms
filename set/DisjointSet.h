#pragma once

#include <unordered_map>

template <typename T>
class DisjointSet {
public:
    ~DisjointSet();

    void add(const T &);
    void unionSets(const T &, const T &);
    T find(const T &);

private:
    struct Node {
        T _element;
        T _root;
        int _rank;

        Node (T element, int rank = 0) : _element(element), _root(element), _rank(rank) {
        }
    };

    std::unordered_map<T, Node *> _sets;
};

template <typename T>
DisjointSet<T>::~DisjointSet() {
    for (auto p = _sets.begin(); p != _sets.end(); ++p)
        delete p->second;
}

template <typename T>
void DisjointSet<T>::add(const T &x) {
    if (_sets.find(x) != _sets.end())
        return;
    _sets[x] = new Node(x);
    return;
}

template <typename T>
void DisjointSet<T>::unionSets(const T &x, const T &y) {
    T r1 = find(x),  r2 = find(y);
    if (_sets[r1]->_rank < _sets[r2]->_rank)
        _sets[r1]->_root = r2;
    else if (_sets[r2]->_rank < _sets[r1]->_rank)
        _sets[r2]->_root = r1;
    else {
        _sets[r2]->_root = r1;
        ++_sets[r1]->_rank;
    }
}

template <typename T>
T DisjointSet<T>::find(const T &x) {
    if (_sets[x]->_root != x)
        _sets[x]->_root = find(_sets[x]->_root);
    return _sets[x]->_root;
}
