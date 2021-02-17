#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int R, C, cnt;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int A[1500][1500];
int melted[1500][1500];
bool visited[1500][1500];
char T[1500];
p swan[2];
queue<p> Q;
bool isInside(int y, int x) {
    return y >= 0 && y < R&& x >= 0 && x < C;
}
bool able(int t) {
    while (!Q.empty()) Q.pop();
    memset(visited, 0, sizeof(visited));
    Q.push(swan[0]);
    visited[swan[0].first][swan[0].second] = 1;
    while (!Q.empty()) {
        const auto [y, x] = Q.front();
        Q.pop();
        if (y == swan[1].first && x == swan[1].second) return true;
        for (int i = 0;i < 4;i++) {
            int ny = y + dir[i][0], nx = x + dir[i][1];
            if (!isInside(ny, nx) || visited[ny][nx] || melted[ny][nx] > t + 1) continue;
            visited[ny][nx] = true;
            Q.push({ ny, nx });
        }
    }
    return false;
}
int main() {
    scanf("%d%d", &R, &C);
    getchar();
    for (int i = 0;i < R;i++) {
        cin.getline(T, C + 1);
        for (int j = 0;j < C;j++) {
            if (T[j] == 'X') A[i][j] = true;
            if (T[j] == 'L') swan[cnt++] = { i,j };
            if (!A[i][j]) {
                melted[i][j] = 1;
                Q.push({ i,j });
            }
        }
    }
    while (!Q.empty()) {
        const auto [y, x] = Q.front();
        Q.pop();
        for (int i = 0;i < 4;i++) {
            int ny = y + dir[i][0], nx = x + dir[i][1];
            if (!isInside(ny, nx) || melted[ny][nx]) continue;
            melted[ny][nx] = melted[y][x] + 1;
            Q.push({ ny,nx });
        }
    }
    int lo = 0, hi = R * C;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (able(mid)) hi = mid - 1;
        else lo = mid + 1;
    }

    printf("%d", lo);
}