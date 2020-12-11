#include <bits/stdc++.h>
using namespace std;
int n, sum;
int main() {
    for (int i = 0;i < 5;i++) {
        scanf("%d", &n);
        sum += n;
    }
    printf("%d", sum);
    return 0;
}