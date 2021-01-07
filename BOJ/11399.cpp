#include <bits/stdc++.h>
using namespace std;
int N, ans, sum;
vector<int> v;
int main() {
    scanf("%d", &N);
    v.resize(N);
    for (int i = 0;i < N;i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for (auto e : v) {
        ans += sum + e;
        sum += e;
    }
    printf("%d", ans);
}