#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
vector <pair<int, int>> P = { { 0,0 },{ 0,1 },{ 1,1 },{ 1,0 } };
void DNC(int y, int x, int n, int m, vector<int> o = { 0,1,2,3 }) {
    if (m <= 0 || m > n * n) return;
    if (n == 1) {
        printf("%d %d", x, y);
        return;
    }
    int nn = n / 2;
    int k = nn * nn;
    DNC(y + P[o[0]].s * nn, x + P[o[0]].f * nn, nn, m, { o[0],o[3],o[2],o[1] });
    DNC(y + P[o[1]].s * nn, x + P[o[1]].f * nn, nn, m - k, o);
    DNC(y + P[o[2]].s * nn, x + P[o[2]].f * nn, nn, m - 2 * k, o);
    DNC(y + P[o[3]].s * nn, x + P[o[3]].f * nn, nn, m - 3 * k, { o[2],o[1],o[0],o[3] });
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    DNC(1, 1, n, m);
}