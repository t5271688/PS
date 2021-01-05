#include <bits/stdc++.h>
using namespace std;
int N, M, ans;
vector<int> adj[1001];
int visited[1001];
int dfs(int curr) {
    visited[curr] = true;
    for (auto next : adj[curr]) if (!visited[next]) dfs(next);
    return 1;
}
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0;i < M;i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1;i <= N;i++) if (!visited[i]) ans += dfs(i);
    printf("%d", ans);
}
