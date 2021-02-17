#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M;
ll A[100000];
int main() {
    scanf("%lld %lld", &N, &M);
    for (int i = 0;i < N;i++) scanf("%lld", A + i);
    ll lo = 0, hi = 1000000000000000000;
    while (lo < hi) {
        ll mid = (lo + hi) >> 1;
        ll T = 0;
        bool flag = false;
        for (int i = 0;i < N;i++) {
            T += mid / A[i];
            if (T >= M) flag = true;
            if (flag) break;
        }
        if (flag) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld", hi);
}