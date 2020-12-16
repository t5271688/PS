#include <bits/stdc++.h>
using namespace std;
const int MAX = 10001;
int N, A[MAX];
vector<int> adj[MAX];
int dp[MAX][2];
bool visited[MAX];
void dfs(int idx) {
    if (visited[idx]) return;
    visited[idx] = true;
    dp[idx][0] = 0;
    dp[idx][1] = A[idx];
    for (int i : adj[idx]) {
        if (visited[i]) continue;
        dfs(i);
        dp[idx][0] += max(dp[i][1], dp[i][0]);
        dp[idx][1] += dp[i][0];
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) scanf("%d", &A[i]);
    for (int i = 0;i < N - 1;i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    printf("%d", max(dp[1][0], dp[1][1]));
}