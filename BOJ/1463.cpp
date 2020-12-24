#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int dyn(int n) {
    int& ret = dp[n];
    if (ret != -1) return ret;
    if (n == 1) return ret = 0;
    ret = dyn(n - 1) + 1;
    if (n % 3 == 0) ret = min(ret, dyn(n / 3) + 1);
    if (n % 2 == 0) ret = min(ret, dyn(n / 2) + 1);
    return ret;
}
int main() {
    int N;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    printf("%d", dyn(N));
}