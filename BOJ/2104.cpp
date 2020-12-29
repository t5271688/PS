#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll A[100000];
ll dnc(int s, int e) {
    if (s == e) return A[s] * A[s];
    int mid = (s + e) / 2;
    ll ret = max(dnc(s, mid), dnc(mid + 1, e));
    ll sum = A[mid], _min = A[mid], l = mid, r = mid;
    while (r - l < e - s) {
        ll q = r < e ? (sum + A[r + 1]) * min(_min, A[r + 1]) : -1;
        ll p = s < l ? (sum + A[l - 1]) * min(_min, A[l - 1]) : -1;
        ll res;
        if (q >= p) {
            _min = min(_min, A[r + 1]);
            res = q;
            sum += A[++r];
        }
        else {
            _min = min(_min, A[l - 1]);
            res = p;
            sum += A[--l];
        }
        ret = max(ret, res);
    }
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
    printf("%lld", dnc(0, N - 1));
}