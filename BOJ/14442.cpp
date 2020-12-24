#include <bits/stdc++.h>
using namespace std;
struct Point {
    int c, y, x;
};
queue<Point> Q;
int A[1001][1001];
int visited[1001][1001][11];
int N, M, K;
bool isInside(int y, int x) {
    return y >= 1 && y <= N && x >= 1 && x <= M;
}
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1;i <= N;i++) for (int j = 1;j <= M;j++) scanf("%1d", &A[i][j]);
    Q.push({ 0,1, 1 });
    visited[1][1][0] = 1;
    while (!Q.empty()) {
        const auto [C, y, x] = Q.front();
        Q.pop();
        if (y == N && x == M) return !printf("%d", visited[y][x][C]);
        for (int i = 0;i < 4;i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1], nc = C + 1;
            if (!isInside(ny, nx)) continue;
            if (!A[ny][nx] && !visited[ny][nx][C]) {
                Q.push({ C,ny,nx });
                visited[ny][nx][C] = visited[y][x][C] + 1;
            }
            if (A[ny][nx] && nc <= K && !visited[ny][nx][nc]) {
                Q.push({ nc,ny,nx });
                visited[ny][nx][nc] = visited[y][x][C] + 1;
            }
        }
    }
    return !printf("-1");
}