#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
    scanf("%d", &t);
    for (int i = 1;i <= t;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
    }
    return 0;
}