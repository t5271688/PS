#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int N, M, A[101][101], check[101][101];
bool isInside(int y, int x) {
    return y >= 0 && y < N&& x >= 0 && x < M;
}
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
deque<p> dq;
int main() {
    memset(check, -1, sizeof(check));
    scanf("%d%d", &M, &N);
    for (int i = 0;i < N;i++) for (int j = 0;j < M;j++) scanf("%1d", &A[i][j]);
    dq.push_back({ 0,0 });
    check[0][0] = 0;
    while (!dq.empty()) {
        auto [y, x] = dq.front();
        dq.pop_front();
        if (y == N - 1 && x == M - 1) return !printf("%d", check[N - 1][M - 1]);
        for (int i = 0;i < 4;i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (!isInside(ny, nx) || check[ny][nx] != -1) continue;
            if (A[ny][nx]) {
                dq.push_back({ ny,nx });
                check[ny][nx] = check[y][x] + 1;
            }
            else {
                dq.push_front({ ny,nx });
                check[ny][nx] = check[y][x];
            }
        }
    }
}