#include <bits/stdc++.h>
using namespace std;
int A[100001][2];
int dp[100001][2];
int dyn(int idx, int c) {
    if (idx < 1) return 0;
    if (idx == 1) return A[idx][c];
    int& ret = dp[idx][c];
    if (ret != -1) return ret;
    return ret = max(dyn(idx - 1, !c), dyn(idx - 2, !c)) + A[idx][c];
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1;i <= N;i++) scanf("%d", &A[i][0]);
        for (int i = 1;i <= N;i++) scanf("%d", &A[i][1]);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", max(dyn(N, 0), dyn(N, 1)));
    }
}