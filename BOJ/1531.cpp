#include <bits/stdc++.h>
using namespace std;
int A[101][101];
int N, M, ans;

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0;i < N;i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int i = y1;i <= y2;i++) for (int j = x1;j <= x2;j++) A[i][j]++;
    }
    for (int i = 1;i <= 100;i++) for (int j = 1;j <= 100;j++) ans += A[i][j] > M;
    printf("%d", ans);
}