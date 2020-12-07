#include <bits/stdc++.h>
using namespace std;
queue<int> Q;
typedef vector<int> vi;
const int MAX = 100001;
int parent[MAX], N, u, v;
vi adj[MAX];
int main() {
    scanf("%d", &N);
    for (int i = 1;i < N;i++) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Q.push(1);
    parent[1] = -1;
    while (!Q.empty()) {
        int top = Q.front();
        Q.pop();
        for (int next : adj[top]) {
            if (!parent[next]) {
                parent[next] = top;
                Q.push(next);
            }
        }
    }
    for (int i = 2;i <= N;i++) printf("%d\n", parent[i]);
    return 0;
}