#include <bits/stdc++.h>
using namespace std;
int N, x;
int A[100000];
int cnt;
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N;i++) scanf("%d", A + i);
    scanf("%d", &x);
    sort(A, A + N);
    int lo = 0, hi = N - 1;
    while (lo < hi) {
        if (A[lo] + A[hi] == x) cnt++, lo++, hi--;
        else if (A[lo] + A[hi] > x) hi--;
        else lo++;
    }
    printf("%d", cnt);
}