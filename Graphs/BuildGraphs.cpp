// Create a graph using Adjacency List (undirected unweighted)
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for(int u=0; u<V; u++) {
            list<int> neighbors = l[u];
            cout << u << " : ";
            for(int v: neighbors) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);
    
    // undirected graph
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    graph.print();

    return 0;
}