#include <bits/stdc++.h>
using namespace std;
int dp[12] = { 0,1,2,4 };
int dyn(int n) {
    if (n < 4) return dp[n];
    int& ret = dp[n];
    if (ret != 0) return ret;
    return ret = dyn(n - 1) + dyn(n - 2) + dyn(n - 3);

}
int main() {
    int N, T;
    for (scanf("%d", &T);T--;) {
        scanf("%d", &N);
        printf("%d\n", dyn(N));
    }
}