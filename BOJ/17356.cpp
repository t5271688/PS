#include <bits/stdc++.h>
using namespace std;
double a, b;
int main() {
    scanf("%lf%lf", &a, &b);
    double m = (b - a) / 400;
    printf("%lf", 1 / ((double)1 + pow(10, m)));
}