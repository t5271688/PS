#include <bits/stdc++.h>
using namespace std;
int N, K, ans;
int A[11];
int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1;i <= N;i++) scanf("%d", A + i);
    for (int i = N;i >= 1;i--) {
        ans += (K / A[i]);
        K %= A[i];
    }
    printf("%d", ans);
}