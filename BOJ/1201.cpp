#include <bits/stdc++.h>
using namespace std;
int N, M, K;

int main() {
    scanf("%d%d%d", &N, &M, &K);
    if (M + K - 1 > N || N > M * K) return !printf("-1");
    for (int i = 0;i < K;i++) {
        for (int j = max(N - M * (i + 1) + 1, K - i);j <= max(N - M * i, K - i);j++) printf("%d ", j);
    }
}