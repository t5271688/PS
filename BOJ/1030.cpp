#include <bits/stdc++.h>
using namespace std;
int s, N, K, R1, R2, C1, C2;
int DNC(int y, int x, int ypos, int xpos, int n, int k) {
    int ret = 0;
    if (n == 1) return 0;
    int kk = (n - k) / 2;
    int nn = n / N;
    if (y >= ypos + kk && y < ypos + kk + k && x >= xpos + kk && x < xpos + kk + k) return 1;
    for (int i = ypos;i < ypos + n;i += nn) {
        for (int j = xpos;j < xpos + n;j += nn) if (y >= i && y < i + nn && x >= j && x < j + nn) ret = DNC(y, x, i, j, nn, k / N);
    }
    return ret;

}
int main() {
    freopen("output2.txt", "w", stdout);
    scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);
    int n = (int)(0.5 + pow(N, s));
    int k = (int)(0.5 + pow(N, s - 1)) * K;
    for (int i = R1;i <= R2;i++) {
        for (int j = C1;j <= C2;j++) printf("%d", DNC(i, j, 0, 0, n, k));
        printf("\n");
    }
}