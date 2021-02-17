#include <bits/stdc++.h>
using namespace std;
int N, C, M, u, v, w, ans;
struct box {
    int s, e, c;
};
vector<box> V;
int capacity[2001];
int main() {
    scanf("%d%d%d", &N, &C, &M);
    fill(capacity + 1, capacity + N + 1, C);
    V.resize(M);
    for (int i = 0;i < M;i++) scanf("%d%d%d", &V[i].s, &V[i].e, &V[i].c);
    sort(V.begin(), V.end(), [](const box& A, const box& B) {return A.e == B.e ? A.s < B.s : A.e < B.e;});
    for (auto E : V) {
        int _min = min(E.c, *min_element(capacity + E.s, capacity + E.e));
        ans += _min;
        for (int i = E.s; i < E.e; i++) capacity[i] -= _min;
    }
    printf("%d", ans);
}