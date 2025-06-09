#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>
using namespace std;

class Graph {
    int V;
    list<int>* l;
    bool isUndir;
public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        l = new list<int> [V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v) {    // u--->v
        l[u].push_back(v);
        if(isUndir)
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

    bool dirCycHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbour = l[src];

        for(int v : neighbour) {
            if(!vis[v]){
                if(dirCycHelper(v, vis, recPath)){
                    return true;
                }
            } else {
                if(recPath[v]){   // cycle condition
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dirCycHelper(i, vis, recPath))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    // directed graph
    Graph graph(4, false);
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    cout << graph.isCycleDir() << endl; // 1

    return 0;
}