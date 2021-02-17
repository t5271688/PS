#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, A[10000];
int main() {
    scanf("%lld%lld", &N, &M);
    for (int i = 0;i < M;i++) scanf("%lld", A + i);
    ll lo = 0, hi = 60000000000LL, T;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        T = M;
        for (ll i = 0;i < M;i++) T += mid / A[i];
        if (T < N) lo = mid + 1;
        else hi = mid - 1;
    }
    T = M;
    lo--;
    for (int i = 0; i < M; i++)
        T += lo / A[i];
    lo++;
    T = lo ? T : 0;
    for (ll i = 0;i < M;i++) {
        if (!(lo % A[i])) T++;
        if (T >= N) return !printf("%lld", i + 1);
    }
}