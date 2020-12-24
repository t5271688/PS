#include <bits/stdc++.h>
using namespace std;
const int M = 1e8;
int main() {
    int n, x;
    for (scanf("%d", &n);n--;) {
        scanf("%d", &x);
        int m = M;
        while ((x % m) == x && m != 10) m /= 10;
        if (x > 10) for (int i = 10;i <= m;i *= 10) x += (x % i >= (5 * i / 10) ? i - x % i : -x % i);
        printf("%d\n", x);
    }
}