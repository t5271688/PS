#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
int N, M, T, K, X, Y;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isInside(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int ans = 0;
        bool visited[50][50]{};
        int A[50][50]{};
        queue<PI> Q;
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++)
        {
            cin >> X >> Y;
            A[Y][X] = 1;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (A[i][j] && !visited[i][j])
                {
                    ans++;
                    Q.push({i, j});
                    visited[i][j] = true;
                    while (!Q.empty())
                    {
                        auto top = Q.front();
                        int y = top.first, x = top.second;
                        Q.pop();
                        for (int i = 0; i < 4; i++)
                        {
                            int nx = x + dir[i][0], ny = y + dir[i][1];
                            if (isInside(ny, nx) && A[ny][nx] && !visited[ny][nx])
                            {
                                Q.push({ny, nx});
                                visited[ny][nx] = true;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}