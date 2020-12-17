#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
struct Planet {
    int x, y, z, id;
};
int N;
int U[100001];
Planet PA[100001];
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
    ll ans = 0;
    int cnt = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) U[i] = i;
    for (int i = 1; i <= N; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        PA[i] = { x,y,z,i };
    }
    sort(PA + 1, PA + N + 1, [](const Planet& A, const Planet& B) {
        return A.x < B.x;
        });
    for (int i = 1; i < N; i++) adj.push_back({ abs(PA[i].x - PA[i + 1].x),{PA[i].id,PA[i + 1].id} });
    sort(PA + 1, PA + N + 1, [](const Planet& A, const Planet& B) {
        return A.y < B.y;
        });
    for (int i = 1; i < N; i++) adj.push_back({ abs(PA[i].y - PA[i + 1].y),{ PA[i].id,PA[i + 1].id } });
    sort(PA + 1, PA + N + 1, [](const Planet& A, const Planet& B) {
        return A.z < B.z;
        });
    for (int i = 1; i < N; i++) adj.push_back({ abs(PA[i].z - PA[i + 1].z),{ PA[i].id,PA[i + 1].id } });

    sort(adj.begin(), adj.end());
    for (int i = 0;; i++) {
        if (Union(adj[i].second.first, adj[i].second.second)) {
            ans += adj[i].first;
            if (++cnt == N - 1) break;
        }
    }
    printf("%lld\n", ans);
}