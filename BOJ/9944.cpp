#include <bits/stdc++.h>
#define CP1 copy(&A[0][0], &A[0][0] + 30 * 30, &T[0][0])
#define CP2 copy(&T[0][0], &T[0][0] + 30 * 30, &A[0][0])
using namespace std;
const int INF = 1e9;
int N, M, T;
int A[30][30];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool isInside(int y, int x) {
    return y >= 0 && y < N&& x >= 0 && x < M;
}
pair<int, int> go(int y, int x, int idx) {
    if (idx == 0) while (isInside(y + 1, x) && !A[y + 1][x]) A[++y][x] = 1;
    if (idx == 1) while (isInside(y, x + 1) && !A[y][x + 1]) A[y][++x] = 1;
    if (idx == 2) while (isInside(y - 1, x) && !A[y - 1][x]) A[--y][x] = 1;
    if (idx == 3) while (isInside(y, x - 1) && !A[y][x - 1]) A[y][--x] = 1;
    return { y,x };
}
bool end(int y, int x) {
    int ret = 0;
    for (int i = 0;i < 4;i++) {
        int ny = y + dir[i][0], nx = x + dir[i][1];
        if (isInside(ny, nx)) ret += !A[ny][nx];
    }
    return !ret;
}
int back_tracking(int y, int x, int level = 0) {
    if (end(y, x)) {
        int unable = 0;
        for (int i = 0;i < N;i++) for (int j = 0;j < M;j++) unable += !A[i][j];
        return unable ? INF : level;
    }
    int ret = INF;
    int T[30][30];
    for (int i = 0;i < 4;i++) {
        if (!isInside(y + dir[i][0], x + dir[i][1]) || A[y + dir[i][0]][x + dir[i][1]]) continue;
        CP1;
        const auto [ny, nx] = go(y, x, i);
        ret = min(ret, back_tracking(ny, nx, level + 1));
        CP2;
    }
    return ret;
}
int main() {
    while (~scanf("%d %d", &N, &M)) {
        for (int i = 0; i < N;i++) {
            getchar();
            for (int j = 0;j < M;j++) {
                char c;
                scanf("%c", &c);
                A[i][j] = c == '*';
            }
        }
        int ans = INF;
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < M;j++) {
                if (!A[i][j]) {
                    A[i][j] = 1;
                    ans = min(ans, back_tracking(i, j));
                    A[i][j] = 0;
                }
            }
        }
        printf("Case %d: %d\n", ++T, ans == INF ? -1 : ans);
    }
}