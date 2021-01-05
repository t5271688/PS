#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int MAXV = 1001;
vi adj[MAXV];
queue<int> Q;
int N, M, V, u, v;
bool visited[MAXV];
void DFS(int curr) {
    visited[curr] = true;
    printf("%d ", curr);
    for (int next : adj[curr]) if (!visited[next]) DFS(next);
}
void BFS() {
    Q.push(V);
    visited[V] = true;
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        printf("%d ", curr);
        for (int next : adj[curr]) {
            if (visited[next]) continue;
            visited[next] = true;
            Q.push(next);
        }
    }
}
int main() {
    scanf("%d%d%d", &N, &M, &V);//정점갯수 N, 간선갯수 M, 시작정점 V
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);//간선 (u,v) 이고 양방향 그래프이므로
        adj[u].push_back(v);// 양쪽 리스트에 다 넣어 준다.
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
    //방문할 수 있는 정점이 여러개인 경우 작은것 먼저 방문하라 하였으므로 오름차순 정렬
    DFS(V);
    //V부터 DFS 시작
    printf("\n");
    memset(visited, false, sizeof(visited));
    //visited 배열 초기화
    BFS();
    //BFS 시작
}