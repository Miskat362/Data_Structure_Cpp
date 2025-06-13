#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
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

    void topologicalHelper(int src, vector<bool> &vis, stack<int> &s) {   // dfs
        vis[src] = true;
 
        list<int> neighbour = l[src];
        for(int v : neighbour) {
            if(!vis[v])
                topologicalHelper(v, vis, s);
        }
        s.push(src);
    }

    void topologicalSort(){
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i=0; i<V; i++){
            if(!vis[i])
                topologicalHelper(i, vis, s);
        }

        // print topological order
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main() {
    // Directed Acyclic Graph (DAG)
    Graph graph(6, false);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topologicalSort();

    return 0;
}