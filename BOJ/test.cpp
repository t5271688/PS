#include <iostream>
long long int a[10];
long long int b[10];
const long long int MOD = 1000000000;
int main() {
    int t, resum;
    long long int sum = 0;
    scanf("%d", &t);
    for (int i = 1; i <= 9; i++) {
        a[i] = b[i] = 1;
    }
    while (t > 1) {
        a[0] = b[1];
        for (int i = 1; i <= 8; i++) {
            a[i] = b[i - 1] + b[i + 1];
            a[i] = a[i] % MOD;
        }
        a[9] = b[8];
        for (int i = 0; i <= 9; i++) {
            b[i] = a[i];
        }
        t--;
    }
    for (int i = 0; i <= 9; i++) {
        sum = (sum + a[i]) % MOD;
    }
    printf("%lld", sum % 1000000000);
}