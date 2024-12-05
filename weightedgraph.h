#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <vector>
#include "Vertex.h"
#include <queue>
using namespace std;

class WeightedGraph {
public:
    WeightedGraph(int);
    bool isEmpty();
    void addVertex(Vertex*);
    void addEdge(int, int, int);
    bool isFull();
    void DFS(Vertex*);
    void BFS(Vertex*);
    Vertex* getVertex(string title); // Updated to take a string title
    void isPath(int source, int destination); // Function to check path and print the path

protected:
    int indexIs(Vertex*);
    void clearMarks();
    void doDFS(Vertex*);
    void doBFS(Vertex*);
    void findPath(int source, int destination); // Helper function to find and print path

private:
    static const int NULL_EDGE = 0;
    int m_numVertices;
    int m_maxVertices;
    vector<Vertex*> m_vertices;
    vector<vector<int>> m_edges;
    vector<bool> m_marks;
};

#endif // WEIGHTEDGRAPH_H
