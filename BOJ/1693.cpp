#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int dp[MAX][17], N, M, ans = 2e9;
vector<int> adj[MAX];
vector<int> faint;
int dyn(int idx, int from, int c) {
    int& ret = dp[idx][c];
    if (ret != -1) return ret;
    ret = c + 1;
    for (int i : adj[idx]) {
        if (i == from) continue;
        int tmp = 2e9;
        for (int j = 0;j < 17;j++) {
            if (j == c) continue;
            tmp = min(tmp, dyn(i, idx, j));
        }
        ret += tmp;
    }
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N - 1;i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d", &M);
    faint.resize(M);
    for (int i = 0;i < M;i++) scanf("%d", &faint[i]);
    sort(faint.begin(), faint.end());
    memset(dp, -1, sizeof(dp));
    for (int i = 0;i < 17;i++)ans = min(ans, dyn(1, -1, i));
    printf("%d", ans);
}