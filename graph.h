//
// Created by chris on 03-Mar-18.
//

#ifndef POO_TEMA1_16_GRAPH_H
#define POO_TEMA1_16_GRAPH_H

#include <iostream>
#include "vector.h"
#include <algorithm>

//TODO find out if default destructors do their job in both classes

template <typename NodeT>
class EdgeList {
    vector <NodeT> edges;
    int _currNode;

public:
    EdgeList() : _currNode(0) {}

    EdgeList(const EdgeList &other) {
        edges = other.edges;
        _currNode = other._currNode;
    }

    explicit EdgeList(int currNode) {
        _currNode = currNode;
    }

//    ~EdgeList() {
//        delete[] edges;
//    }

    void sort() {
        edges.mergeSort(0, edges.size() - 1);
    }

    inline int getNode() const {
        return _currNode;
    }

    inline int size() const {
        return edges.size();
    }

    NodeT &operator [](const int& index) const {
        return edges[index];
    }

    EdgeList &operator = (const EdgeList &other) {
        edges = other.edges;
        _currNode = other._currNode;
    }

    bool operator == (const EdgeList &other) const {
        if (edges.size() == other.size()) {
            bool areEqual = true;
            for (int i = 0; i < edges.size(); ++i) {
                 areEqual = std::min(areEqual, edges[i] == other[i]);
            }

            return areEqual;
        }

        return false;
    }

    bool operator != (const EdgeList &other) const {
        return !(*this == other);
    }

    bool operator < (const EdgeList &other) const {
        return _currNode < other._currNode;
    }
};

template <typename NodeT>
class Graph {
    int _nodeCnt;
    vector <EdgeList <NodeT>> G;

public:
    Graph() : _nodeCnt(0) {}

    explicit Graph(int nodeCnt) {
        _nodeCnt = nodeCnt;
        G.resize(nodeCnt);
    }

    Graph(const Graph &other) {
        _nodeCnt = other._nodeCnt;
        for (int i = 0; i < _nodeCnt; ++i) {
            G[i] = other[i];
        }
    }

//    ~Graph() {
//        delete[] G;
//    }

    //TODO read graph
    std::istream &operator >> (std::istream &is) {
        int m;
        is >> _nodeCnt >> m;
        for (int i = 0; i < m)
        return is;
    }

    //TODO print graph
    std::ostream &operator << (std::ostream &os) {
        os << _nodeCnt << '\n';


        return os;
    }

    inline int size() const {
        return _nodeCnt;
    }

    void sort() {
        G.mergeSort(0, G.size() - 1);
        for (int edgeListInd = 0; edgeListInd < G.size(); ++edgeListInd) {
            G[edgeListInd].sort();
        }
    }

    //TODO RoyFloyd
    vector<vector<int>> royFloyd() {

    }

    //TODO intermediary nodes in shortest path between any 2 nodes
    vector <int> shortestPath(int node1, int node2) {
        vector <int> ans;

        return ans;
    }

    //TODO connected components
    vector <vector<int>> connectedComponents() {

    }

    //TODO find out if graph is connected
    bool isConnected() {

    }

    //TODO minimum spanning tree of a connected component
    Graph minSpanningTree(vector <int> CC) {

    }

    //TODO * meaning the intersection of 2 graphs where each edge has the minimum weight of the 2
    Graph &operator * (const Graph &other) const {
        Graph g1 = *this;
        Graph g2 = other;

        g1.sort();
        g2.sort();
    }

    EdgeList <NodeT> &operator [] (const int &index) const {
        return G[index];
    }

    Graph &operator = (const Graph &other) {
        _nodeCnt = other._nodeCnt;
        for (int i = 0; i < _nodeCnt; ++i) {
            G[i] = other[i];
        }

        return *this;
    }

    bool operator == (const Graph &other) const {
//        return _nodeCnt == other._nodeCnt;

        Graph g1 = *this;
        Graph g2 = other;

        g1.sort();
        g2.sort();

        if (g1.size() == g2.size()) {
            bool areEqual = true;

            for (int edgeListInd = 0; edgeListInd < g1.size() and areEqual; ++edgeListInd) {
                if (g1[edgeListInd].size() != g2[edgeListInd].size()) {
                    areEqual = false;
                }

                for (int nodeInd = 0; nodeInd < g1[edgeListInd].size() and areEqual; ++nodeInd) {
                    if (g1[edgeListInd][nodeInd] != g2[edgeListInd][nodeInd]) {
                        areEqual = false;
                    }
                }
            }

            return areEqual;
        }

        return false;
    }

    bool operator != (const Graph &other) const {
        return !(*this == other);
    }

    bool operator < (const Graph &other) const {
        _nodeCnt < other._nodeCnt;
    }
};

#endif //POO_TEMA1_16_GRAPH_H
