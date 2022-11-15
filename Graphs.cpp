//
// Created by Lenovo on 11/15/2022.
//

#include "bits/stdc++.h"

using namespace std;

class Graph {
private:
    bool** adj_matrix;    // Adjacency Matrix
    list<int> *adj_lists; // Adjacency List

    int num_vertices;

public:
    explicit Graph(int num_vertices) {
        this->num_vertices = num_vertices;
        adj_matrix = new bool * [num_vertices];

        for (int i = 0; i < num_vertices; ++i) {
            adj_matrix[i] = new bool [num_vertices];
            for (int j = 0; j < num_vertices; ++j) {
                adj_matrix[i][j] = false;
            }
        }
    }

    void addEdge(int i , int j) {
        adj_matrix[i][j] = true;
        adj_matrix[j][i] = true;
    }

    void removeEdge(int i, int j) {
        adj_matrix[i][j] = false;
        adj_matrix[i][j] = false;
    }

    void print() {
        for (int i = 0; i < num_vertices; ++i) {
            cout << i +1 << ": ";
            for (int j = 0; j < num_vertices; ++j) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addEdge(vector<int> adj[],int s, int d) {
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    void print_list(vector<int> adj[], int v) {
        for (int i = 0; i < v ; ++i) {
            cout << "\nVertex " << i << " :";
            for (auto j: adj[i]) {
                cout << "->" << j;
            }
        }
    }

};

int main () {
    vector<int> adj[4];
    Graph graph(4);

    graph.addEdge(1,0);
    graph.addEdge(2,1);
    graph.addEdge(2,1);

    graph.print();
    graph.addEdge(adj,1,2);
    graph.addEdge(adj,2,3);
    graph.addEdge(adj,1,3);
    graph.print_list(adj,4);
    return 0;
}