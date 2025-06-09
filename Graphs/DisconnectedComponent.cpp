#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfsHelper(int u, vector<bool> &vis)
    {
        queue<int> q;
        q.push(u);
        vis[u] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbour = l[u];
            for (int v : neighbour)
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void bfs()
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bfsHelper(i, vis); // Corrected to bfsHelper
                cout << endl;
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis)
    {
        vis[u] = true;
        cout << u << " ";

        list<int> neighbour = l[u];
        for (int v : neighbour)
        {
            if (!vis[v])
                dfsHelper(v, vis);
        }
    }

    void dfs(int V)
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfsHelper(i, vis); // starting pt i
            cout << endl;
        }
    }
};

int main()
{
    Graph graph(10);

    // undirected graph
    graph.addEdge(0, 2);
    graph.addEdge(2, 5);
    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 9);
    graph.addEdge(4, 3);
    graph.addEdge(3, 8);
    graph.addEdge(3, 7);

    graph.dfs(7);
    graph.bfs();

    return 0;
}