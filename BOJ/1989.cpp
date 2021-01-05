#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, int, int> ti;
ll A[100001];
ti DNC(int s, int e) {
    if (s == e) return { A[s] * A[s],s,s };
    int mid = (s + e) / 2;
    ti left = DNC(s, mid);
    ti right = DNC(mid + 1, e);
    ti middle = { 0,0,0 };
    ll sum = A[mid], m = A[mid];
    int l = mid, r = mid;
    while (r - l < e - s) {
        ll q = r < e ? (sum + A[r + 1]) * min(m, A[r + 1]) : -1;
        ll p = s < l ? (sum + A[l - 1]) * min(m, A[l - 1]) : -1;
        ll res;
        if (q >= p) {
            m = min(m, A[r + 1]);
            sum += A[++r];
            res = q;
        }
        else {
            m = min(m, A[l - 1]);
            sum += A[--l];
            res = p;
        }
        if (res > get<0>(middle)) middle = { res,l,r };
    }
    return max({ left,right,middle });
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) scanf("%d", A + i);
    auto [val, s, e] = DNC(1, N);
    printf("%lld\n%d %d", val, s, e);
}
