#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int main() {
    int N;
    scanf("%d", &N);
    vector<p> v(N);
    for (int i = 0;i < N;i++) scanf("%d%d", &v[i].second, &v[i].first);
    sort(v.begin(), v.end());
    for (auto e : v) printf("%d %d\n", e.second, e.first);
}