#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<pi> v;
int ans, e, N;
int main() {
    scanf("%d", &N);
    v.resize(N);
    for (int i = 0;i < N;i++) scanf("%d%d", &v[i].second, &v[i].first);
    sort(v.begin(), v.end());
    for (int i = 0;i < N;i++) {
        if (v[i].second >= e) {
            e = v[i].first;
            ans++;
        }
    }
    printf("%d", ans);
}