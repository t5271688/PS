#include <bits/stdc++.h>
using namespace std;
int ans;
int N;
vector<int> v;
int p(int idx) {
    int ret = 0, m = 1e9;
    int r = idx + 2 >= N - 1 ? N - 1 : idx + 2;
    for (int i = idx;i <= r;i++) {
        ret += v[i];
        m = min(m, v[i]);
    }
    return r - idx != 2 ? ret : ret - m;
}
int main() {
    scanf("%d", &N);
    v.resize(N);
    for (int i = 0;i < N;i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0;i < N;i += 3) ans += p(i);
    printf("%d", ans);
}