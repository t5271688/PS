#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int N, S;
bool isInside(int y, int x) {
    return y > 0 && y <= N && x > 0 && x <= N;
}
int A[801][801];
int visited[801][801];
queue<p> origin_bee;
queue<p> origin_teddy;
queue<p> bee;
queue<p> teddy;
bool bfs(int t) {
    bee = origin_bee;
    teddy = origin_teddy;
    memset(visited, 0, sizeof(visited));
    for (int i = 0;i < t;i++) {
        int sz = bee.size();
        for (int i = 0;i < sz;i++) {
            const auto [y, x] = bee.front();
            bee.pop();
            for (int i = 0;i < 4;i++) {
                int ny = y + dir[i][0], nx = x + dir[i][1];
                if (!isInside(ny, nx) || A[ny][nx] > 2 || visited[ny][nx] == 2) continue;
                visited[ny][nx] = 2;
                bee.push({ ny, nx });
            }
        }
    }
    while (!teddy.empty()) {
        for (int i = 0;i < S;i++) {
            int sz = teddy.size();
            for (int i = 0;i < sz;i++) {
                const auto [y, x] = teddy.front();
                teddy.pop();
                if (visited[y][x] == 2) continue;
                if (A[y][x] == 3) return true;
                for (int i = 0;i < 4;i++) {
                    int ny = y + dir[i][0], nx = x + dir[i][1];
                    if (!isInside(ny, nx) || A[ny][nx] == 4 || A[ny][nx] == 2 || visited[ny][nx]) continue;
                    visited[ny][nx] = 1;
                    teddy.push({ ny,nx });
                }
            }
        }
        int sz = bee.size();
        for (int i = 0;i < sz;i++) {
            const auto [y, x] = bee.front();
            bee.pop();
            for (int i = 0;i < 4;i++) {
                int ny = y + dir[i][0], nx = x + dir[i][1];
                if (!isInside(ny, nx) || A[ny][nx] > 2 || visited[ny][nx] == 2) continue;
                visited[ny][nx] = 2;
                bee.push({ ny, nx });
            }
        }
    }
    return false;
}
int main() {
    scanf("%d %d", &N, &S);
    for (int i = 1;i <= N;i++) {
        getchar();
        for (int j = 1;j <= N;j++) {
            char c;
            scanf("%c", &c);
            if (c == 'T') A[i][j] = 4;
            if (c == 'G') A[i][j] = 0;
            if (c == 'D') A[i][j] = 3;
            if (c == 'H') {
                A[i][j] = 2;
                origin_bee.push({ i,j });
            }
            if (c == 'M') {
                A[i][j] = 0;
                origin_teddy.push({ i,j });
            }
        }
    }
    int lo = 0, hi = N * N * 2;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (bfs(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    printf("%d", hi);
}