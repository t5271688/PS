#include <bits/stdc++.h>
using namespace std;
int A[1001], N;
int dp[1001][2];
int main() {
    int max = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", A + i);
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < i; j++)
            if (A[i] > A[j] && dp[i][0] <= dp[j][0] + 1) dp[i][0] = dp[j][0] + 1;
    for (int i = N; i > 0; i--)
        for (int j = N + 1; j > i; j--)
            if (A[i] > A[j] && dp[i][1] <= dp[j][1] + 1) dp[i][1] = dp[j][1] + 1;
    for (int i = 1; i <= N; i++)
        if (max < dp[i][0] + dp[i][1]) max = dp[i][0] + dp[i][1];
    printf("%d", max - 1);
}