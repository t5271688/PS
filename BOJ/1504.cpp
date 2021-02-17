#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_V = 805;
const ll INF = 2e9;
typedef pair<int, int> P;
int dist[MAX_V];
bool visited[MAX_V];
int N, E, P1, P2, u, v, w;
vector<P> adj[MAX_V];
void Dijkstra(int V) {
    fill(dist, dist + MAX_V, INF);
    fill(visited, visited + MAX_V, false);
    priority_queue < P, vector<P>, greater<P>> PQ;
    dist[V] = 0;
    PQ.push({ 0,V });
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
    ll T1, T2, NT1, NT2, PP;
    ll path1 = INF, path2 = INF;
    scanf("%d%d", &N, &E);
    while (E--) {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    scanf("%d%d", &P1, &P2);
    Dijkstra(1);
    T1 = dist[P1];
    T2 = dist[P2];
    Dijkstra(N);
    NT1 = dist[P1];
    NT2 = dist[P2];
    Dijkstra(P1);
    PP = dist[P2];
    path1 = T1 + NT2 + PP;
    path2 = T2 + NT1 + PP;
    printf("%lld\n", (path1 >= INF && path2 >= INF) ? -1 : min(path1, path2));
}