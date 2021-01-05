#include <bits/stdc++.h>
using namespace std;
struct Point {
    int c, y, x;
    bool day;
};
queue<Point> Q;
int A[1001][1001];
int visited[1001][1001][11][2];
int N, M, K;
bool isInside(int y, int x) {
    return y >= 1 && y <= N && x >= 1 && x <= M;
}
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1;i <= N;i++) for (int j = 1;j <= M;j++) scanf("%1d", &A[i][j]);
    Q.push({ 0,1, 1,1 });
    visited[1][1][0][1] = 1;
    while (!Q.empty()) {
        auto [C, y, x, d] = Q.front();
        Q.pop();
        if (y == N && x == M) return !printf("%d", visited[y][x][C][d]);
        if (!d && !visited[y][x][C][!d]) {
            Q.push({ C,y,x,!d });
            visited[y][x][C][!d] = visited[y][x][C][d] + 1;
        }
        for (int i = 0;i < 4;i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1], nc = C + 1;
            if (!isInside(ny, nx)) continue;
            if (!A[ny][nx] && !visited[ny][nx][C][!d]) {
                Q.push({ C,ny,nx,!d });
                visited[ny][nx][C][!d] = visited[y][x][C][d] + 1;
            }
            if (d && A[ny][nx] && nc <= K && !visited[ny][nx][nc][!d]) {
                Q.push({ nc,ny,nx,!d });
                visited[ny][nx][nc][!d] = visited[y][x][C][d] + 1;
            }
        }
    }
    return !printf("-1");
}