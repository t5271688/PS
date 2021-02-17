#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> P;
int U[10001];
int N, M, cnt;
vector<P> adj;
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
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) U[i] = i;
    int ans = 0;
    while (M--) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        adj.push_back({ w,{ a,b } });
    }
    sort(adj.begin(), adj.end());
    for (int i = 0;;i++) {
        if (Union(adj[i].second.first, adj[i].second.second)) {
            ans += adj[i].first;
            if (++cnt == N - 1) break;
        }
    }
    printf("%d\n", ans);
}