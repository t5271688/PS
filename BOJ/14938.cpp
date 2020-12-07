#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int m, n, r, u, v, w, ans;
int dist[101][101], item[101];
int main() {
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 1;i <= n;i++) scanf("%d", &item[i]);
    for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) dist[i][j] = i == j ? 0 : INF;
    for (int i = 0;i < r;i++) {
        scanf("%d%d%d", &u, &v, &w);
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for (int i = 1;i <= n;i++) {
        int temp = 0;
        for (int j = 1;j <= n;j++) if (dist[i][j] <= m) temp += item[j];
        ans = max(ans, temp);
    }
    printf("%d", ans);
    return 0;
}