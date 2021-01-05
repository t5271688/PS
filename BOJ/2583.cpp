#include <bits/stdc++.h>
using namespace std;
int M, N, K;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool isInside(int y, int x) {
    return y < M&& y >= 0 && x < N&& x >= 0;
}
bool visited[100][100];
int A[100][100];
vector<int> ans;
int dfs(int y, int x) {
    visited[y][x] = true;
    int ret = 1;
    for (int i = 0;i < 4;i++) {
        int ny = y + dir[i][0], nx = x + dir[i][1];
        if (!isInside(ny, nx) || visited[ny][nx] || A[ny][nx]) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}
int main() {
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 0;i < K;i++) {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int i = y1;i < y2;i++) for (int j = x1;j < x2;j++) A[i][j] = 1;
    }
    for (int i = 0;i < M;i++) for (int j = 0;j < N;j++) if (!A[i][j] && !visited[i][j]) ans.push_back(dfs(i, j));
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto e : ans) printf("%d ", e);
}