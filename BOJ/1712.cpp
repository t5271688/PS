#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main() {
    scanf("%lld%lld%lld", &a, &b, &c);
    if (c - b <= 0) return !printf("-1");
    printf("%lld", 1 + a / (c - b));
}