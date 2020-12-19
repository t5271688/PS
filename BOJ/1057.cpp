#include <bits/stdc++.h>
using namespace std;
int n, a, b, t;
int main() {
    scanf("%d%d%d", &n, &a, &b);
    a--, b--;
    while (1) {
        if (!a && !b) return !printf("-1");
        a /= 2;
        b /= 2;
        t++;
        if (a == b) return !printf("%d", t);
    }
}