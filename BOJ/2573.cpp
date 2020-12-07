#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int N, M;
bool isInside(int y, int x) {
    return y >= 0 && y < N&& x >= 0 && x < M;
}
int A[300][300];
bool visited[300][300];
void dfs(int y, int x) {
    visited[y][x] = true;
    int water = 0;
    for (int i = 0;i < 4;i++) {
        int ny = y + dir[i][0], nx = x + dir[i][1];
        water += !A[ny][nx];
    }
    for (int i = 0;i < 4;i++) {
        int ny = y + dir[i][0], nx = x + dir[i][1];
        if (isInside(ny, nx) && A[ny][nx] && !visited[ny][nx]) dfs(ny, nx);
    }
    A[y][x] = A[y][x] - water < 0 ? 0 : A[y][x] - water;
}
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0;i < N;i++) for (int j = 0;j < M;j++) scanf("%d", &A[i][j]);
    int t = 0;
    while (++t) {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < M;j++) {
                if (A[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if (cnt >= 2) return !printf("%d", t - 1);
        if (!cnt) return !printf("0");
    }
}