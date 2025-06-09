#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>
using namespace std;

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {    // u---v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for(int u=0; u<V; u++){
            list<int> neighbors = l[u];
            cout << u << " : ";
            for(int v : neighbors){
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool undirCycHelper(int src, int par, vector<bool> &vis){
        vis[src] = true;
        list<int> neighbour = l[src];

        for(int v : neighbour) {
            if(!vis[v]){
                if(undirCycHelper(v, src, vis)){
                    return true;
                }
            } else {
                if(v != par){   // cycle condition
                    return true;
                }
            }
        }
    }

    bool isCycleUdir(){
        vector<bool> vis(V, false);
        return undirCycHelper(0, -1, vis);
    }

    void dfs(int u, vector<bool> &vis) {
        cout << u << " ";

    }
};

int main() {
    int V = 5;
    Graph graph(V);
    
    // undirected graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);

    graph.addEdge(1, 2);

    graph.addEdge(3, 4);

    cout << graph.isCycleUdir() << endl;    // 1

    return 0;
}