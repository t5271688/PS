#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
vector<p> adj[100001];
bool visited[100001];
int N, target, ans;
void dfs(int curr, int cost) {
    visited[curr] = true;
    if (cost > ans) {
        ans = cost;
        target = curr;
    }
    for (auto next : adj[curr]) if (!visited[next.first]) dfs(next.first, cost + next.second);
}
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        int u;
        scanf("%d", &u);
        while (1) {
            int v, w;
            scanf("%d", &v);
            if (v == -1) break;
            scanf("%d", &w);
            adj[u].push_back({ v,w });
        }
    }
    dfs(1, 0);
    ans = 0;
    memset(visited, 0, sizeof(visited));
    dfs(target, 0);
    printf("%d", ans);
}