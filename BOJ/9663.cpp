#include <bits/stdc++.h>
using namespace std;
int N, col[15];
bool chk(int n) {
    for (int i = 0;i < n;i++) {
        if (col[i] == col[n] || n - i == abs(col[n] - col[i])) return false;
    }
    return true;
}
int back_tracking(int idx = 0) {
    if (idx == N) return 1;
    int ret = 0;
    for (int i = 0;i < N;i++) {
        col[idx] = i;
        if (chk(idx)) ret += back_tracking(idx + 1);
    }
    return ret;
}
int main() {
    scanf("%d", &N);
    printf("%d", back_tracking());
}