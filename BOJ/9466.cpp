#include <bits/stdc++.h>
using namespace std;
int A[100001];
int visited[100001];
int dfs(int curr) {
    visited[curr] = 1;
    int next = A[curr], ret = 0;
    if (visited[next]) {
        if (visited[next] == 1) {
            for (int tmp = next;tmp != curr;tmp = A[tmp]) ret++;
            ret++;
        }
    }
    else ret = dfs(next);
    visited[curr] = 2;
    return ret;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, ans = 0;
        scanf("%d", &N);
        for (int i = 1;i <= N;i++) scanf("%d", A + i);
        memset(visited, 0, sizeof(visited));
        for (int i = 1;i <= N;i++) if (!visited[i]) ans += dfs(i);
        printf("%d\n", N - ans);
    }
}