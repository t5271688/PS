#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAX_V = 1001;
const int INF = 2e9;
bool visited[1001];
vector<P> adj[MAX_V];
int N, M, X, ans = 0;
int dist[MAX_V][MAX_V];
void Dijkstra(vector<P>* adj, int S) {
    fill(dist[S], dist[S] + MAX_V, INF);
    fill(visited, visited + MAX_V, false);
    priority_queue < P, vector<P>, greater<P>> PQ;
    dist[S][S] = 0;
    PQ.push({ 0,S });
    while (!PQ.empty()) {
        int curr;
        do {
            curr = PQ.top().second;
            PQ.pop();
        } while (!PQ.empty() && visited[curr]);
        if (visited[curr]) break;
        visited[curr] = true;
        for (auto& p : adj[curr]) {
            int next = p.first, d = p.second;
            if (dist[S][next] > dist[S][curr] + d) {
                dist[S][next] = dist[S][curr] + d;
                PQ.push({ dist[S][next],next });
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &X);
    for (int i = 0;i < M;i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({ v,w });
    }
    for (int i = 1;i <= N;i++) Dijkstra(adj, i);
    for (int i = 1;i <= N;i++) ans = max(ans, dist[i][X] + dist[X][i]);
    printf("%d", ans);
}