#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9;
int m[101][101], N, K, L, D;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
queue<P> Q;
deque<P> DQ;
bool isInside(int b, int a) {
    return b > 0 && b <= N && a > 0 && a <= N;
}
int snake() {
    int X = 0;
    while (true) {
        auto [ny, nx] = DQ.front();
        ny += dir[D][0], nx += dir[D][1];
        if (!isInside(ny, nx) || m[ny][nx] == INF) return X + 1;
        if (!m[ny][nx]) {
            m[DQ.back().first][DQ.back().second] = 0;
            DQ.pop_back();
        }
        m[ny][nx] = INF;
        DQ.push_front({ ny,nx });
        X++;
        if (!Q.empty()) {
            auto [x, y] = Q.front();
            if (x == X) {
                Q.pop();
                D += y;
                D = D < 0 ? 3 : D % 4;
            }
        }
    }
}
int main() {
    m[1][1] = INF;
    DQ.push_back({ 1,1 });
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        m[a][b] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int t;
        char d;
        scanf("%d %c", &t, &d);
        Q.push({ t,d == 'L' ? -1 : 1 });
    }
    printf("%d", snake());
}