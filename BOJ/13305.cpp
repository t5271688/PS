#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
int dist[100001];
ll ans, curr = 1e10;
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N - 1;i++) scanf("%d", &dist[i]);
    for (int i = 0;i < N - 1;i++) {
        ll a;
        scanf("%lld", &a);
        curr = min(curr, a);
        ans += curr * dist[i];
    }
    printf("%lld", ans);
}