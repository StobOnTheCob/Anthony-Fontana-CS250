/*
    Anthony Fontana
    Dr.V
    CS250

    This program implements a weighted graph, and conducts a
    DPS and a BFS on the graph. It can also be given a source node
    and a destination node to search and see if a path exists there.

*/


#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"
using namespace std;

int main() {
    WeightedGraph myGraph(10);
    Vertex* startNode;

    // Adding vertices to the graph
    startNode = new Vertex("A"); myGraph.addVertex(startNode); // A-0
    startNode = new Vertex("B"); myGraph.addVertex(startNode); // B-1
    startNode = new Vertex("C"); myGraph.addVertex(startNode); // C-2
    startNode = new Vertex("D"); myGraph.addVertex(startNode); // D-3
    startNode = new Vertex("E"); myGraph.addVertex(startNode); // E-4

    // Adding edges to the graph
    myGraph.addEdge(1, 0, 10); // B -> A (weight 10)
    myGraph.addEdge(2, 1, 20); // C -> B (weight 20)
    myGraph.addEdge(0, 2, 12); // A -> C (weight 12)
    myGraph.addEdge(0, 3, 60); // A -> D (weight 60)
    myGraph.addEdge(3, 2, 32); // D -> C (weight 32)
    myGraph.addEdge(4, 0, 7);  // E -> A (weight 7)

    // Perform DFS and BFS starting from vertex "E"
    Vertex* startVertex = myGraph.getVertex("E");
    if (startVertex) {
        cout << "DFS starting from E: ";
        myGraph.DFS(startVertex);
        cout << endl;

        cout << "BFS starting from E: ";
        myGraph.BFS(startVertex);
        cout << endl << endl;
    } else {
        cout << "Vertex E not found!" << endl;
    }

    // Path testing

    myGraph.isPath(4, 1); // Check if path exists from E to B (should find path with 39w)
    cout << endl;

    myGraph.isPath(4, 3); // Check if path exists from E to D (should find path with 67w)
    cout << endl;

    myGraph.isPath(0, 4); // Check if path exists from A to E (path should not exist)

    return 0;
}
