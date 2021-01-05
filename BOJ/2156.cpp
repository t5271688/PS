#include <bits/stdc++.h>
using namespace std;
int N;
int A[10001];
int dp[10001];
int dyn(int idx) {
    if (idx < 1) return 0;
    int& ret = dp[idx];
    if (ret != -1) return ret;
    return ret = max({ dyn(idx - 1), dyn(idx - 2) + A[idx],dyn(idx - 3) + A[idx] + A[idx - 1] });
}
int main() {
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) scanf("%d", A + i);
    memset(dp, -1, sizeof(dp));
    printf("%d", dyn(N));
}