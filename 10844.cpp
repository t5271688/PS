#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9;
ll dp[101][10], ans;
int N;
ll dyn(int n, int prev) {
    if (n == N) return 1;
    ll& ret = dp[n][prev];
    if (ret != -1) return ret;
    ret = 0;
    ret += prev == 9 ? 0 : dyn(n + 1, prev + 1);
    ret += prev == 0 ? 0 : dyn(n + 1, prev - 1);
    return ret %= MOD;
}
int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    for (int i = 1;i <= 9;i++) ans = (ans + dyn(1, i)) % MOD;
    printf("%lld", ans);
}