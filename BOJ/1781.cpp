#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int N, ans;
vector<p> prob;
priority_queue<int> PQ;
int main() {
    scanf("%d", &N);
    prob.resize(N);
    for (int i = 0;i < N;i++) scanf("%d%d", &prob[i].first, &prob[i].second);
    sort(prob.begin(), prob.end(), greater<p>());
    for (int i = 200000, j = 0;i >= 1;i--) {
        while (j < N && prob[j].first >= i) PQ.push(prob[j++].second);
        if (PQ.empty()) continue;
        ans += PQ.top();
        PQ.pop();
    }
    printf("%d", ans);
}