#include <bits/stdc++.h>
using namespace std;
int A[65][65], N;
void quadtree(int y, int x, int n) {
    bool complete = true;
    for (int i = y;i < y + n;i++) for (int j = x;j < x + n;j++) complete &= (A[y][x] == A[i][j]);
    if (complete) printf("%d", A[y][x]);
    else {
        printf("(");
        for (int i = y;i < y + n;i += n / 2) for (int j = x;j < x + n;j += n / 2) quadtree(i, j, n / 2);
        printf(")");
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N;i++) for (int j = 0;j < N;j++) scanf("%1d", &A[i][j]);
    quadtree(0, 0, N);
}