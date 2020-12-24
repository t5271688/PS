#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;
int dp[1001];
int dyn(int n) {
    int& ret = dp[n];
    if (ret != -1) return ret;
    if (n < 3) return ret = n;
    return ret = (dyn(n - 1) + dyn(n - 2)) % MOD;
}
int main() {
    int N;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    printf("%d", dyn(N));
}