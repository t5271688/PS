#include <bits/stdc++.h>
using namespace std;
int A[3000][3000];
int cnt[3];
void paper(int x, int y, int n) {
    bool complete = true;
    for (int i = y;i < y + n;i++) for (int j = x;j < x + n;j++) complete &= (A[y][x] == A[i][j]);
    if (complete) cnt[A[y][x] + 1]++;
    else for (int i = y; i < y + n; i += n / 3) for (int j = x; j < x + n; j += n / 3) paper(j, i, n / 3);

}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
    paper(0, 0, N);
    for (int i = 0; i < 3; i++) printf("%d\n", cnt[i]);
}