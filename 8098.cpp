#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dp[30001];
int n, p, k, ans, e;
vector<pii> v;
int dyn(int idx) {
    if (idx <= 0) return 0;
    int& ret = dp[idx];
    if (ret != -1) return ret;
    if (idx == 1) return ret = v[1].first - v[1].second;
    int t = upper_bound(v.begin(), v.end(), pii{ v[idx].second,v[idx].second }) - v.begin() - 1;
    return ret = max(dyn(idx - 1), dyn(t) + v[idx].first - v[idx].second);
}
int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    v.push_back({ -1e9,-1e9 });
    for (int i = 0;i < n;i++) {
        scanf("%d%d", &p, &k);
        v.push_back({ k,p });
    }
    memset(dp, -1, sizeof(dp));
    sort(v.begin(), v.end());
    printf("%d", dyn(n));
    return 0;
}