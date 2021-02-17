#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        vector<int> adj[505];
        bool A[505][505] = { 0, };
        int indegree[505] = { 0, };
        int n, m, u = 0, v = 0, status = 0;
        scanf("%d", &n);
        vector<int> V(n), ans(n);
        for (int i = 0;i < n;i++) scanf("%d", &V[i]);
        scanf("%d", &m);
        for (int i = 0;i < m;i++) {
            scanf("%d %d", &u, &v);
            A[u][v] = true;
            A[v][u] = true;
        }
        for (int i = 0;i < n;i++) {
            for (int j = i + 1;j < n;j++) {
                u = V[i], v = V[j];
                if (!A[u][v]) {
                    adj[u].push_back(v);
                    indegree[v]++;
                }
                else {
                    adj[v].push_back(u);
                    indegree[u]++;
                }
            }
        }
        queue<int> Q;
        for (int i = 0;i < n;i++) if (!indegree[V[i]]) Q.push(V[i]);
        for (int i = 0;i < n;i++) {
            if (Q.size() >= 2) {
                status = 1;
                break;
            }
            if (Q.empty()) {
                status = 2;
                break;
            }
            int curr = Q.front();
            Q.pop();
            ans[i] = curr;
            for (int next : adj[curr]) {
                if (--indegree[next] == 0) Q.push(next);
            }
        }
        if (status) status == 1 ? puts("?") : puts("IMPOSSIBLE");
        else {
            for (int e : ans) printf("%d ", e);
            printf("\n");
        }
    }
}