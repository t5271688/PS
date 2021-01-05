#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[100001];
ll DNC(int s, int e) {
    if (s == e) return A[s];
    int mid = (s + e) / 2;
    ll left = DNC(s, mid);
    ll right = DNC(mid + 1, e);
    ll middle = 0;
    ll sum = 1, m = A[mid];
    int l = mid, r = mid;
    while (r - l < e - s) {
        ll q = r < e ? (sum + 1) * min(m, A[r + 1]) : -1;
        ll p = s < l ? (sum + 1) * min(m, A[l - 1]) : -1;
        if (q >= p) {
            m = min(m, A[++r]);
            sum++;
            middle = max(middle, q);
        }
        else {
            m = min(m, A[--l]);
            sum++;
            middle = max(middle, p);
        }
    }
    return max({ left,right,middle });
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) scanf("%lld", A + i);
    printf("%lld\n", DNC(1, N));
}