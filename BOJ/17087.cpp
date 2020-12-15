#include <bits/stdc++.h>
using namespace std;
int n, s, ans = 2e9;
int a[100005];
int main() {
    scanf("%d%d", &n, &s);
    for (int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        a[i] = abs(a[i] - s);
    }
    for (int i = 0;i < n - 1;i++) {
        int g = gcd(a[i], a[i + 1]);
        ans = min(ans, g);
    }
    printf("%d", ans);
}