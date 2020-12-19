#include <bits/stdc++.h>
using namespace std;
double A[1002];
int N, L, ans;
double done;
int main() {
    scanf("%d%d", &N, &L);
    for (int i = 0;i < N;i++) scanf("%lf", &A[i]);
    sort(A, A + N);
    for (int i = 0;i < N;i++) {
        if (A[i] + 0.5 <= done) continue;
        ans++;
        if (done >= A[i] - 0.5) done += L;
        else done = A[i] - 0.5 + L;
    }
    printf("%d", ans);
}