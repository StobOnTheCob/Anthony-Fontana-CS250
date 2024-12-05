#include "WeightedGraph.h"
#include <iostream>
#include <queue>
using namespace std;

WeightedGraph::WeightedGraph(int size) {
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size);
    for (int i = 0; i < size; i++) {
        m_vertices[i] = NULL;
    }
    m_marks.resize(size);
    int rows = size;
    int columns = size;
    m_edges.resize(rows, vector<int>(columns, 0));
}

void WeightedGraph::addVertex(Vertex* aVertex) {
    m_vertices[m_numVertices] = aVertex;
    for (int i = 0; i < m_maxVertices; i++) {
        m_edges[m_numVertices][i] = NULL_EDGE;
        m_edges[i][m_numVertices] = NULL_EDGE;
    }
    m_numVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight) {
    int row = indexIs(m_vertices[fromVertex]);
    int column = indexIs(m_vertices[toVertex]);
    m_edges[row][column] = weight;
}

int WeightedGraph::indexIs(Vertex* aVertex) {
    int i = 0;
    while (i < m_numVertices) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
        i++;
    }
    return -1;
}

void WeightedGraph::clearMarks() {
    for (int i = 0; i < m_numVertices; i++) {
        m_marks[i] = false;
    }
}

void WeightedGraph::doDFS(Vertex* aVertex) {
    int ix, ix2;
    if (aVertex == NULL) return;
    cout << aVertex->getTitle() << " ";
    ix = indexIs(aVertex);
    m_marks[ix] = true;
    for (int i = 0; i < m_numVertices; i++) {
        ix2 = indexIs(m_vertices[i]);
        if (m_edges[ix][ix2] != NULL_EDGE) {
            if (m_marks[i] == false)
                doDFS(m_vertices[i]);
        }
    }
}

void WeightedGraph::DFS(Vertex* aVertex) {
    clearMarks();
    doDFS(aVertex);
}

void WeightedGraph::doBFS(Vertex* aVertex) {
    int ix, ix2;
    queue<Vertex*> que;
    ix = indexIs(aVertex);
    m_marks[ix] = true;
    que.push(aVertex);
    while (!que.empty()) {
        Vertex* node = que.front();
        que.pop();
        ix = indexIs(node);
        cout << node->getTitle() << " ";
        for (int i = 0; i < m_numVertices; i++) {
            ix2 = indexIs(m_vertices[i]);
            if (m_edges[ix][ix2] != NULL_EDGE) {
                if (m_marks[ix2] == false) {
                    m_marks[i] = true;
                    que.push(m_vertices[i]);
                }
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* aVertex) {
    clearMarks();
    doBFS(aVertex);
}

Vertex* WeightedGraph::getVertex(string title) {
    for (int i = 0; i < m_numVertices; i++) {
        if (m_vertices[i]->getTitle() == title) {
            return m_vertices[i];
        }
    }
    return nullptr; // Return nullptr if no vertex with that title is found
}

void WeightedGraph::isPath(int source, int destination) {
    vector<bool> visited(m_numVertices, false);
    vector<int> parent(m_numVertices, -1);
    queue<int> que;

    visited[source] = true;
    que.push(source);

    while (!que.empty()) {
        int current = que.front();
        que.pop();

        if (current == destination) {
            vector<int> path;
            int totalWeight = 0;

            // Reconstruct the path and calculate total weight
            for (int v = destination; v != -1; v = parent[v]) {
                path.push_back(v);
                if (parent[v] != -1) {
                    totalWeight += m_edges[parent[v]][v];
                }
            }

            // Output the path
            cout << "Path from " << m_vertices[source]->getTitle() << " to "
                 << m_vertices[destination]->getTitle() << ": ";
            for (int i = path.size() - 1; i >= 0; --i) {
                cout << m_vertices[path[i]]->getTitle();
                if (i > 0) cout << " -> ";
            }

            // Output the number of edges and total weight
            cout << "\nLength of the path: " << (path.size() - 1) << " edges." << endl;
            cout << "Total weight of the path: " << totalWeight << endl;
            return;
        }

        for (int i = 0; i < m_numVertices; i++) {
            if (m_edges[current][i] != NULL_EDGE && !visited[i]) {
                visited[i] = true;
                parent[i] = current;
                que.push(i);
            }
        }
    }

    cout << "No path exists from " << m_vertices[source]->getTitle() << " to "
         << m_vertices[destination]->getTitle() << "." << endl;
}
