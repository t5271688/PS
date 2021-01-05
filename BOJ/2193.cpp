#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, ans;
ll dp[91][2];
ll dyn(int idx, int prev) {
    if (idx == 1) return prev;
    ll& ret = dp[idx][prev];
    if (ret != -1) return ret;
    ret = prev ? 0 : dyn(idx - 1, 1);
    return ret += dyn(idx - 1, 0);
}
int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    printf("%lld", dyn(N, 1) + dyn(N, 0));
}