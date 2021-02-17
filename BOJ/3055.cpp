#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int R, C, T;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char A[51][51];
bool visited[51][51];
queue<P> water;
queue<P> Q;
bool isInside(int y, int x) {
    return y >= 0 && y < R&& x >= 0 && x < C;
}
int main() {
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf(" %s", A[i]);
        for (int j = 0; j < C; j++) {
            if (A[i][j] == '*') water.push({ i,j });
            if (A[i][j] == 'S') {
                visited[i][j] = true;
                Q.push({ i,j });
            }
        }
    }
    while (++T) {
        int qsize = water.size();
        for (int i = 0; i < qsize; i++) {
            auto [y, x] = water.front(); water.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dir[i][0], nx = x + dir[i][1];
                if (!isInside(ny, nx)) continue;
                if (A[ny][nx] == 'X' || A[ny][nx] == 'D' || A[ny][nx] == '*') continue;
                A[ny][nx] = '*';
                water.push({ ny,nx });
            }
        }
        qsize = Q.size();
        if (!qsize) return !printf("KAKTUS");
        for (int i = 0; i < qsize; i++) {
            auto [y, x] = Q.front(); Q.pop();
            if (A[y][x] == 'D') return !printf("%d", T - 1);
            for (int i = 0; i < 4; i++) {
                int ny = y + dir[i][0], nx = x + dir[i][1];
                if (!isInside(ny, nx)) continue;
                if (visited[ny][nx] || A[ny][nx] == 'X' || A[ny][nx] == '*') continue;
                visited[ny][nx] = true;
                Q.push({ ny,nx });
            }
        }
    }
}