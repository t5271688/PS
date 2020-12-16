#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (a % b) return gcd(b, a % b);
    return b;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d", gcd(a, b), lcm(a, b));
}