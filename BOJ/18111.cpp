#include <bits/stdc++.h>
using namespace std;
int m[500][500], N, M, B, H, T = 2e9;
int main()
{
    scanf("%d %d %d", &N, &M, &B);
    for (int i = 0;i < N;i++) for (int j = 0;j < M;j++) scanf("%d", &m[i][j]);
    for (int h = 0;h <= 256;h++)
    {
        int t = 0, b = B;
        for (int i = 0;i < N;i++)
        {
            for (int j = 0;j < M;j++)
            {
                if (m[i][j] == h) continue;
                if (m[i][j] > h) {
                    t += 2 * (m[i][j] - h);
                    b += m[i][j] - h;
                }
                if (m[i][j] < h)
                {
                    t += h - m[i][j];
                    b -= h - m[i][j];
                }
            }
        }
        if (b >= 0 && t <= T) {
            H = h;
            T = t;
        }
    }
    printf("%d %d", T, H);
    return 0;
}