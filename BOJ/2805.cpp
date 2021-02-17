#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[1000000];
ll N, M;
int main() {
    scanf("%lld%lld", &N, &M);
    for (int i = 0;i < N;i++) scanf("%lld", A + i);
    ll lo = 0, hi = 1e9;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll ret = 0;
        for (int i = 0;i < N;i++) if (mid < A[i]) ret += A[i] - mid;
        if (ret >= M) lo = mid + 1;
        else hi = mid - 1;
    }
    printf("%lld", hi);
}