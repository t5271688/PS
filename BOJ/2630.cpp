#include <bits/stdc++.h>
using namespace std;
int A[129][120];
int cnt[2];
void paper(int x, int y, int n) {
    bool complete = true;
    for (int i = y;i < y + n;i++) for (int j = x;j < x + n;j++) complete &= (A[y][x] == A[i][j]);
    if (complete) cnt[A[y][x]]++;
    else for (int i = y; i < y + n; i += n / 2) for (int j = x; j < x + n; j += n / 2) paper(j, i, n / 2);

}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
    paper(0, 0, N);
    for (int i = 0; i < 2; i++) printf("%d\n", cnt[i]);
}