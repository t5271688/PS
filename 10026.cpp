#include <bits/stdc++.h>
using namespace std;
int N, ans1, ans2;
char s[101][101];
bool visited[101][101];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool isInside(int y, int x) {
    return y >= 0 && y < N&& x >= 0 && x < N;
}
int dfs1(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dir[i][0], nx = x + dir[i][1];
        if (isInside(ny, nx) && !visited[ny][nx] && s[ny][nx] == s[y][x]) dfs1(ny, nx);
    }
    return 1;
}
int dfs2(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dir[i][0], nx = x + dir[i][1];
        if (isInside(ny, nx) && !visited[ny][nx]) {
            if ((s[y][x] == 'R' || s[y][x] == 'G') && (s[ny][nx] == 'R' || s[ny][nx] == 'G')) dfs2(ny, nx);
            else if (s[y][x] == s[ny][nx]) dfs2(ny, nx);
        }
    }
    return 1;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf(" %s", s[i]);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (!visited[i][j]) ans1 += dfs1(i, j);
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (!visited[i][j]) ans2 += dfs2(i, j);
    printf("%d %d", ans1, ans2);
}