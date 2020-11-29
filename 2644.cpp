#include <bits/stdc++.h>
using namespace std;
queue<int> Q;
typedef vector<int> vi;
const int MAX = 101;
int dist[MAX], N, u, v, s, t, m;
vi adj[MAX];
int main() {
    scanf("%d %d %d %d", &N, &s, &t, &m);
    for (int i = 0;i < m;i++) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Q.push(s);
    dist[s] = 1;
    while (!Q.empty()) {
        int top = Q.front();
        Q.pop();
        if (top == t) {
            printf("%d", dist[t] - 1);
            return 0;
        }
        for (int next : adj[top]) {
            if (!dist[next]) {
                dist[next] = dist[top] + 1;
                Q.push(next);
            }
        }
    }
    printf("-1");
    return 0;
}