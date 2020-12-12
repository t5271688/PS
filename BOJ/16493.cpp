#include <bits/stdc++.h>

using namespace std;
int p[21], d[21];
int dp[201][21], n, m;
int dyn(int c, int idx) {
    if (!idx) return 0;
    int& ret = dp[c][idx];
    if (ret != -1) return ret;
    ret = dyn(c, idx - 1);
    if (c >= d[idx]) ret = max(ret, dyn(c - d[idx], idx - 1) + p[idx]);
    return ret;

}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= m;i++) scanf("%d%d", &d[i], &p[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d", dyn(n, m));
}