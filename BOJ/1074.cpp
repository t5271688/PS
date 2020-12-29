#include <bits/stdc++.h>
using namespace std;
void Z(int N, int r, int c, int res) {
    if ((r < 0 || r >= N) || (c < 0 || c >= N)) return;
    if (r == 0 && c == 0) {
        printf("%d", res);
        return;
    }
    int nn = N / 2;
    int k = nn * nn;
    Z(nn, r, c, res);
    Z(nn, r, c - nn, res + k);
    Z(nn, r - nn, c, res + k * 2);
    Z(nn, r - nn, c - nn, res + k * 3);

}
int main() {
    int N, r, c;
    scanf("%d%d%d", &N, &r, &c);
    N = (int)pow(2, N);
    Z(N, r, c, 0);
}