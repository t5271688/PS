#include <bits/stdc++.h>
using namespace std;
int N, P[1001];
int dp[1001];
int dyn(int n) {
    if (!n) return 0;
    int& ret = dp[n];
    if (ret != 0) return ret;
    for (int i = 1;i <= n;i++) ret = max(ret, dyn(n - i) + P[i]);
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) scanf("%d", P + i);
    printf("%d", dyn(N));
}