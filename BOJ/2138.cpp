#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int A[100001][2];
int B[100001];
int  N;
int p(int idx, bool u) {
    int a = idx == 0 ? 0 : idx - 1;
    int b = idx == N - 1 ? N - 1 : idx + 1;
    for (int i = a;i <= b;i++) A[i][u] = !A[i][u];
    return 1;
}
int f(bool u) {
    int ret = 0;
    bool able = true;
    if (u) ret += p(0, u);
    for (int i = 0;i < N - 1;i++) {
        if (A[i][u] != B[i]) ret += p(i + 1, u);
        if (i == N - 2 && A[N - 1][u] != B[N - 1]) able = false;
    }

    return able ? ret : INF;
}
int main() {
    int ans;
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%1d", &A[i][0]);
        A[i][1] = A[i][0];
    }
    for (int i = 0;i < N;i++) scanf("%1d", &B[i]);
    ans = min(f(0), f(1));
    printf("%d", ans == INF ? -1 : ans);
}