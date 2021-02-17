#include <bits/stdc++.h>
using namespace std;
int visited[200][200];
int dir[6][2] = { {-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1} };
int N;
bool isInside(int y, int x) {
    return y >= 0 && y < N&& x >= 0 && x < N;
}
queue<pair<int, int>> Q;
int main() {
    int r1, c1, r2, c2;
    scanf("%d", &N);
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    Q.push({ r1,c1 });
    visited[r1][c1] = 1;
    while (!Q.empty()) {
        const auto [r, c] = Q.front();
        Q.pop();
        if (r == r2 && c == c2) return !printf("%d", visited[r][c] - 1);
        for (int i = 0;i < 6;i++) {
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (!isInside(nr, nc) || visited[nr][nc]) continue;
            visited[nr][nc] = visited[r][c] + 1;
            Q.push({ nr,nc });
        }
    }
    printf("%d", -1);
}