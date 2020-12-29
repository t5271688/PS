#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sieve[1000001];
int ans;
ll a, b;
int main() {
    scanf("%lld%lld", &a, &b);
    for (ll i = 2;i <= sqrt(b);i++) {
        ll t = i * i;
        ll l = ceil((double)a / t);
        ll r = floor((double)b / t);
        for (ll j = l;j <= r;j++) sieve[j * t - a] = true;
    }
    for (ll i = 0;i <= (b - a);i++) ans += !sieve[i];
    printf("%d", ans);
}