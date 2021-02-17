#include <bits/stdc++.h>
using namespace std;
int N, C;
int A[200000];
int main() {
    scanf("%d%d", &N, &C);
    for (int i = 0;i < N;i++) scanf("%d", A + i);
    sort(A, A + N);
    int lo = 0, hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int T = A[0], cnt = 1;
        for (int i = 1;i < N;i++) if (A[i] - T >= mid) T = A[i], cnt++;
        if (cnt >= C) lo = mid + 1;
        else hi = mid - 1;
    }
    printf("%d", hi);
}