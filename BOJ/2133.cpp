#include <bits/stdc++.h>
using namespace std;
int N;
int dp1[31];
int dp2[31];
int dyn(int n);
int dyn2(int n);
int main() {
    scanf("%d", &N);
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    printf("%d", dyn(N));
}
int dyn(int n) {
    if (!n) return !n;
    if (n % 2) return 0;
    int& ret = dp1[n];
    if (ret != -1) return ret;
    return ret = dyn(n - 2) + 2 * dyn2(n - 1);
}
int dyn2(int n) {
    if (n <= 1) return n;
    int& ret = dp2[n];
    if (ret != -1) return ret;
    return ret = dyn(n - 1) + dyn2(n - 2);
}