#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> v;
int main() {
    scanf("%d%d", &N, &K);
    v.resize(N);
    for (int i = 0;i < N;i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    printf("%d", v[K - 1]);
}