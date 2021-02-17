#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int A[9][9];
bool col[10][10];
bool row[10][10];
bool sqr[10][10];
vector<p> v;
int calc(int y, int x) {
    return (y / 3) * 3 + (x / 3);
}
void back_tracking(int n = 0) {
    if (n == v.size()) {
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) printf("%d ", A[i][j]);
            printf("\n");
        }
        exit(0);
    }
    const auto [y, x] = v[n];
    for (int i = 1;i <= 9;i++) {
        if (!col[x][i] && !row[y][i] && !sqr[calc(y, x)][i]) {
            A[y][x] = i;
            row[y][i] = true;
            col[x][i] = true;
            sqr[calc(y, x)][i] = true;
            back_tracking(n + 1);
            A[y][x] = 0;
            row[y][i] = false;
            col[x][i] = false;
            sqr[calc(y, x)][i] = false;
        }
    }
}
int main() {
    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9;j++) {
            scanf("%d", &A[i][j]);
            if (A[i][j]) {
                row[i][A[i][j]] = true;
                col[j][A[i][j]] = true;
                sqr[calc(i, j)][A[i][j]] = true;
            }
            else v.push_back({ i,j });
        }
    }
    back_tracking();
}