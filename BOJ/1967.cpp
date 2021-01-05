#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
vector<p> adj[10001];
bool visited[10001];
int t, dist;
void dfs(int curr, int cost) {
    visited[curr] = true;
    if (cost > dist) {
        t = curr;
        dist = cost;
    }
    for (auto next : adj[curr]) if (!visited[next.first]) dfs(next.first, cost + next.second);

}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0;i < N - 1;i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    dfs(t, 0);
    printf("%d", dist);
}