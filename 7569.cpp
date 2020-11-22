#include <bits/stdc++.h>
using namespace std;
struct Point {
    int z, y, x;
};
queue<Point> Q;
int N, M, H, ans;
int A[100][100][100];
int dir[6][3] = { {1, 0,0}, {-1,0, 0}, {0,1, 0}, {0, -1,0},{0,0,1},{0,0,-1} };
bool isInside(int z, int y, int x) {
    return y >= 0 && y < N&& x >= 0 && x < M&& z >= 0 && z < H;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> M >> N >> H;
    for (int i = 0;i < H;i++) {
        for (int j = 0;j < N;j++) {
            for (int k = 0;k < M;k++) {
                cin >> A[i][j][k];
                if (A[i][j][k] == 1) Q.push({ i, j, k });
            }
        }
    }
    while (!Q.empty()) {
        auto top = Q.front();
        Q.pop();
        int z = top.z, y = top.y, x = top.x;
        for (int i = 0; i < 6; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1], nz = z + dir[i][2];
            if (isInside(nz, ny, nx) && !A[nz][ny][nx]) {
                A[nz][ny][nx] = A[z][y][x] + 1;
                Q.push({ nz, ny, nx });
            }
        }
    }
    for (int i = 0;i < H;i++) {
        for (int j = 0;j < N;j++) {
            for (int k = 0;k < M;k++) {
                if (!A[i][j][k]) return !printf("-1");;
                ans = max(ans, A[i][j][k]);
            }
        }
    }
    cout << ans - 1;
}