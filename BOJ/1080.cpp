#include <bits/stdc++.h>
using namespace std;
int A[50][50];
int B[50][50];
int flip(int y, int x) {
    for (int i = y;i <= y + 2;i++)for (int j = x;j <= x + 2;j++) A[i][j] = !A[i][j];
    return 1;
}
int main() {
    int N, M, ans = 0;
    scanf("%d%d", &N, &M);
    for (int i = 0;i < N;i++) for (int j = 0;j < M;j++) scanf("%1d", &A[i][j]);
    for (int i = 0;i < N;i++) for (int j = 0;j < M;j++) scanf("%1d", &B[i][j]);
    for (int i = 0;i < N - 2;i++) for (int j = 0;j < M - 2;j++) if (A[i][j] != B[i][j]) ans += flip(i, j);
    bool flag = true;
    for (int i = 0;i < N;i++) for (int j = 0;j < M;j++) if (A[i][j] != B[i][j]) flag = false;
    printf("%d", flag ? ans : -1);
}