#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
typedef pair<int, int> p;
int V, E, K;
vector<p> adj[300001];
int dist[20001];
bool visited[20001];
void Dijkstra(vector<p>* adj) {
    fill(dist + 1, dist + V + 1, INF);
    priority_queue < p, vector<p>, greater<p>> PQ;
    dist[K] = 0;
    PQ.push({ 0,K });
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
            if (dist[next] > dist[curr] + d) {
                dist[next] = dist[curr] + d;
                PQ.push({ dist[next],next });
            }
        }
    }
}
int main() {
    scanf("%d%d%d", &V, &E, &K);
    for (int i = 0;i < E;i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({ v, w });
    }
    Dijkstra(adj);
    for (int i = 1;i <= V;i++) dist[i] == INF ? puts("INF") : printf("%d\n", dist[i]);
}