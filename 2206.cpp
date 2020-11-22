#include <bits/stdc++.h>
using namespace std;
struct Point {
    bool c;
    int y, x;
};
queue<Point> Q;
int A[1001][1001];
int visited[1001][1001][2];
int N, M;
bool isInside(int y, int x) {
    return y >= 1 && y <= N && x >= 1 && x <= M;
}
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    for (int i = 1;i <= N;i++) for (int j = 1;j <= M;j++) scanf("%1d", &A[i][j]);
    Q.push({ false,1, 1 });
    visited[1][1][0] = 1;
    while (!Q.empty()) {
        auto top = Q.front();
        Q.pop();
        bool C = top.c;
        int y = top.y, x = top.x;
        if (y == N && x == M) return !printf("%d", visited[y][x][C]);
        for (int i = 0;i < 4;i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (!isInside(ny, nx)) continue;
            if (!A[ny][nx] && !visited[ny][nx][C]) {
                Q.push({ C,ny,nx });
                visited[ny][nx][C] = visited[y][x][C] + 1;
            }
            if (A[ny][nx] && !C && !visited[ny][nx][!C]) {
                Q.push({ !C,ny,nx });
                visited[ny][nx][!C] = visited[y][x][C] + 1;
            }
        }
    }
    return !printf("-1");
}