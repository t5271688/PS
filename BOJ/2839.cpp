#include <bits/stdc++.h>
using namespace std;
int dp[5001];
int dyn(int n) {
    if (n < 0) return 1e9;
    if (n == 0) return 0;
    int& ret = dp[n];
    if (ret != -1) return ret;
    return ret = min(dyn(n - 3), dyn(n - 5)) + 1;
}
int main() {
    int N;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    printf("%d", dyn(N) > 5000 ? -1 : dp[N]);
}