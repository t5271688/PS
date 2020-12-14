#include <bits/stdc++.h>
using namespace std;
int N;
double max1, a, sum;
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%lf", &a);
        sum += a;
        max1 = max(max1, a);
    }
    printf("%lf", sum / max1 * 100 / N);
}