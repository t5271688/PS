#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100001;
typedef pair<int, pair<int, int>> P;
int N, M, ans, cnt;
int U[MAX_V];
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
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) U[i] = i;
    while (M--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj.push_back({ c,{ a,b} });
    }
    sort(adj.begin(), adj.end());
    for (int i = 0;;i++) {
        if (Union(adj[i].second.first, adj[i].second.second)) {
            ans += adj[i].first;
            if (++cnt == N - 2) break;
        }
    }
    printf("%d\n", ans);
}