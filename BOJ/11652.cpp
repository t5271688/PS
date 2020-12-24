#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, cnt;
ll ans;
int main() {
    scanf("%d", &N);
    vector<ll> v(N);
    for (int i = 0;i < N;i++) scanf("%lld", &v[i]);
    sort(v.begin(), v.end());
    ans = v[0];
    int t = 1;
    cnt = 1;
    for (int i = 1;i < v.size();i++) {
        if (v[i] == v[i - 1]) t++;
        else t = 1;
        if (cnt < t) {
            cnt = t;
            ans = v[i];
        }
    }
    printf("%lld", ans);
}