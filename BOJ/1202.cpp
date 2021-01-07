#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
vector<P> jewels;
vector<int> bag;
priority_queue<int> PQ;
int N, K;
long long ans;
int main() {
    scanf("%d%d", &N, &K);
    jewels.resize(N);
    bag.resize(K);
    for (int i = 0;i < N;i++) scanf("%d%d", &jewels[i].first, &jewels[i].second);
    for (int i = 0;i < K;i++) scanf("%d", &bag[i]);
    sort(jewels.begin(), jewels.end());
    sort(bag.begin(), bag.end());
    for (int i = 0, j = 0;i < K;i++) {
        while (j < N && jewels[j].first <= bag[i]) PQ.push(jewels[j++].second);
        if (PQ.empty()) continue;
        ans += PQ.top();
        PQ.pop();
    }
    printf("%lld", ans);
}