#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9;
ll dp[101][10], ans;//dp[n][prev] = n자리수이고, leading number가 prev인 계단수를 만드는 방법의 수
int N;
ll dyn(int n, int prev) {
    if (n == 1) return 1;//n==1일떄(한자리 수 일때)는 모든 수가 계단 수이다.(기저 사례)
    ll& ret = dp[n][prev];
    if (ret != -1) return ret;
    ret = 0;
    ret += prev == 9 ? 0 : dyn(n - 1, prev + 1);//9일때를 제외하고는 다음 수가 +1만큼 차이나는 prev를 가질 수 있음
    ret += prev == 0 ? 0 : dyn(n - 1, prev - 1);//0일때를 제외하고는 다음 수가 -1만큼 차이나는 prev를 가질 수 있음
    return ret %= MOD;
}
int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));//불가능한 가짓수인 -1가지로 초기화
    for (int i = 1;i <= 9;i++) ans = (ans + dyn(N, i)) % MOD;//N자리수이고, i를 leading number로 가지는 계단수를 추가(N자리 수이며 1~9를 leading number로 가짐)
    printf("%lld", ans);
}