#include "Graph.h"
#include <iostream>


// Constructor
template <typename T>
Graph<T>::Graph(int vertices, bool directed)
    : V(vertices), directed(directed) {
    adjList.resize(V);
}

// Add an edge
template <typename T>
void Graph<T>::addEdge(int u, int v, T weight) {

    //can't add a self edge
    if(u == v) {
        cout << "cant add self edge' "<< std::endl;
        return;
    }
    //does it matter that add adds to the front instead of the back?
    adjList[u].add({v, weight});
    if (!directed) {
        adjList[v].add({u, weight});
    }
}

// Get number of nodes
template <typename T>
int Graph<T>::getNumVertices() const{
	return V;
}

// Print the adjacency list
template <typename T>
void Graph<T>::printGraph() const {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        vector<pair<int, T>> neighbors = adjList[i].toVector();
        for (const auto& neighbor : neighbors) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

// Get neighbors of a vertex
template <typename T>
const LinkedBag<pair<int, T>>& Graph<T>::getNeighbors(int vertex) const {
    return adjList[vertex];
}


// DFS Traversal (Recursive approach)
template <typename T>
void Graph<T>::DFT(int start, vector<User> users) const {
    vector<bool> visited(V, false); // To keep track of visited vertices
    DFTRecursive(start, visited, users);
    cout << endl;
}

// Utility function for DFS (Recursive)
template <typename T>
void Graph<T>::DFTRecursive(int v, vector<bool>& visited, vector<User> users) const {
    visited[v] = true;
    cout << v << " "; // Visit the current vertex
    cout << users[v] << endl;

    // Recur for all the vertices adjacent to this vertex
    vector<pair<int, T>> neighbors = adjList[v].toVector();
    for (const auto& neighbor : neighbors) {
        if (!visited[neighbor.first]) {
            DFTRecursive(neighbor.first, visited, users);
            // cout<<neighbor.first<< std::endl;
        }
    }
}

template <typename T>
bool Graph<T>::DFS(int start, vector<User> users, string search) const {
    vector<bool> visited(V, false); // To keep track of visited vertices
    bool value = DFSRecursive(start, visited, users, search);
    cout << endl;
    return value;
}

template <typename T>
bool Graph<T>::DFSRecursive(int v, vector<bool>& visited, vector<User> users, string search) const {
    visited[v] = true;
    cout << v << " "; // Visit the current vertex
    cout << users[v] << endl;

    if(users[v].getUsername() == search) {
        return true;
    }

    // Recur for all the vertices adjacent to this vertex
    vector<pair<int, T>> neighbors = adjList[v].toVector();
    for (const auto& neighbor : neighbors) {
        if (!visited[neighbor.first]) {
            return DFSRecursive(neighbor.first, visited, users, search);
            
            // cout<<neighbor.first<< std::endl;
        }
    }
    return false;
}


// -----------------------------------------------------
// Depth First Search (by username)
// TO DO 
// Add DFS implementation 
// Add DFSRecursive implementation 
