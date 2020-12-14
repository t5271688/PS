#include <bits/stdc++.h>
using namespace std;
int a, sum;
int main() {
    for (int i = 0;i < 5;i++) {
        scanf("%d", &a);
        sum += a * a;
    }
    printf("%d", sum % 10);
}