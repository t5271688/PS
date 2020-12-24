#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;
int dp[1001][10], ans; // dp[n][prev] = n자리수이고, leading number가 prev인 오르막수를 만드는 방법의 수
int dyn(int n, int prev) {
    if (n == 1) return 1;//n==1일떄(한자리 수 일때)는 모든 수가 오르막 수이다.(기저 사례)
    int& ret = dp[n][prev];
    if (ret) return ret;
    for (int i = prev;i <= 9;i++) ret = (ret + dyn(n - 1, i)) % MOD;//자릿수가 n-1이고, 현재의 leading number 이상인 prev를 가진 오르막 수의 갯수 합함
    return ret;
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0;i <= 9;i++) ans = (ans + dyn(N, i)) % MOD;//N자리수이고, i를 leading number로 가지는 오르막수를 추가(N자리 수이며 0~9를 leading number로 가짐)
    printf("%d", ans);
}