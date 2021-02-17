#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
double dist(const P& A, const P& B) {
    return sqrt((A.first - B.first) * (A.first - B.first)
        + (A.second - B.second) * (A.second - B.second));
}
vector<pair<double, P>> adj;
vector<P> V;
int U[1001], N, M, cnt = 0;
double ans;
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
    for (int i = 0;i < N;i++) {
        U[i + 1] = i + 1;
        long long x, y;
        scanf("%lld%lld", &x, &y);
        V.push_back({ x,y });
    }
    for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) adj.push_back({ dist(V[i],V[j]),{ i + 1,j + 1 } });
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        cnt += Union(a, b);
    }
    sort(adj.begin(), adj.end());
    for (int i = 0;;i++) {
        if (Union(adj[i].second.first, adj[i].second.second)) {
            ans += adj[i].first;
            if (++cnt == N - 1) break;
        }
    }
    printf("%.2lf\n", ans);
}