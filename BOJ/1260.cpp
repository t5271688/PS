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
    scanf("%d%d%d", &N, &M, &V);//�������� N, �������� M, �������� V
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);//���� (u,v) �̰� ����� �׷����̹Ƿ�
        adj[u].push_back(v);// ���� ����Ʈ�� �� �־� �ش�.
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
    //�湮�� �� �ִ� ������ �������� ��� ������ ���� �湮�϶� �Ͽ����Ƿ� �������� ����
    DFS(V);
    //V���� DFS ����
    printf("\n");
    memset(visited, false, sizeof(visited));
    //visited �迭 �ʱ�ȭ
    BFS();
    //BFS ����
}