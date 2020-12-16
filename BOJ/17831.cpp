#include <bits/stdc++.h>
using namespace std;
const int MAX = 200001;
int dp[MAX][2];
int A[MAX];
int N;
vector<int> child[MAX];
int dyn(int idx, bool used) {
    int& ret = dp[idx][used];
    if (!child[idx].size()) return ret = 0;
    if (ret != -1) return ret;
    int p = 0;
    for (int i : child[idx]) p += dyn(i, 0);
    ret = max(ret, p);
    if (!used) for (int i : child[idx]) ret = max(ret, p + (A[i] * A[idx]) - dyn(i, 0) + dyn(i, 1));
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 2;i <= N;i++) {
        int t;
        scanf("%d", &t);
        child[t].push_back(i);
    }
    for (int i = 1;i <= N;i++) scanf("%d", &A[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d", dyn(1, 0));
}