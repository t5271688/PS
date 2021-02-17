#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> P;
vector<P> adj;
int N, M, ans, cnt;
int U[1001];
int Find(int n) {
    if (U[n] == n) return n;
    return U[n] = Find(U[n]);
}
bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return false;
    U[b] = a;
    return true;
}
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) U[i] = i;
    while (M--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj.push_back({ w,{u,v} });
    }
    sort(adj.begin(), adj.end());
    for (int i = 0;;i++) {
        if (Union(adj[i].second.first, adj[i].second.second)) {
            ans += adj[i].first;
            cnt++;
            if (cnt == N - 1) break;
        }
    }
    printf("%d", ans);
}