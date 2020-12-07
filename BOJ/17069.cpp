#include <bits/stdc++.h>
using namespace std;
#define horizontal 0
#define vertical 1
#define diagonal 2
typedef long long ll;
int N;
ll A[33][33];
ll dp[33][33][3];
ll dyn(int y, int x, int dir) {
    if (y < 1 || y > N || x < 1 || x > N) return 0;
    ll& ret = dp[y][x][dir];
    if (ret != -1) return ret;
    if (y == N && x == N) return ret = 1;
    ret = 0;
    if (dir != vertical && !A[y][x + 1])  ret += dyn(y, x + 1, horizontal);
    if (dir != horizontal && !A[y + 1][x])  ret += dyn(y + 1, x, vertical);
    if (!A[y][x + 1] && !A[y + 1][x] && !A[y + 1][x + 1]) ret += dyn(y + 1, x + 1, diagonal);
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%d", &A[i][j]);
    memset(dp, -1, sizeof(dp));
    printf("%lld", dyn(1, 2, horizontal));
}