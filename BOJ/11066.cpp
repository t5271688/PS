#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int A[501], S[501];
int dp[501][501];
int dyn(int s, int e) {
    if (s == e) return 0;
    int& ret = dp[s][e];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = s;i <= e;i++) ret = min(ret, dyn(s, i) + dyn(i + 1, e));
    return ret = ret + S[e] - S[s - 1];
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1;i <= N;i++) scanf("%d", A + i), S[i] = S[i - 1] + A[i];
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dyn(1, N));
    }
}