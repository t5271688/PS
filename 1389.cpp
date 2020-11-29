#include <bits/stdc++.h>
using namespace std;
int N, M, _min = 1e9, ans;
vector<int> adj[101];
bool visited[101];
int bfs(int curr) {
    int ret = 0;
    queue<int> Q;
    visited[curr] = true;
    Q.push(curr);
    int a = 0;
    while (!Q.empty()) {
        int qsize = Q.size();
        a++;
        for (int i = 0; i < qsize; i++) {
            int now = Q.front(); Q.pop();
            for (int next : adj[now]) {
                if (!visited[next]) {
                    ret += a;
                    visited[next] = true;
                    Q.push(next);
                }
            }
        }
    }
    return ret;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for (int i = 1; i <= N; i++) {
        int res = bfs(i);
        if (_min > res) {
            _min = res;
            ans = i;
        }
        fill(visited, visited + N + 1, 0);
    }
    cout << ans;
}