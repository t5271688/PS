#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 101;
vector<int> adj[MAX_V];
bool visited[MAX_V];
int DFS(int current)
{
    int ret = 1;
    visited[current] = true;
    for (int next : adj[current])
    {
        if (!visited[next])
            ret += DFS(next);
    }
    return ret;
}
int main()
{
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << DFS(1) - 1;
}