#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
vector<p> univ;
priority_queue<int> PQ;
int n, ans;
int main() {
    scanf("%d", &n);
    univ.resize(n);
    for (int i = 0;i < n;i++) scanf("%d%d", &univ[i].second, &univ[i].first);
    sort(univ.begin(), univ.end(), greater<p>());
    for (int i = 10000, j = 0;i >= 1;i--) {
        while (j < n && univ[j].first >= i) PQ.push(univ[j++].second);
        if (PQ.empty()) continue;
        ans += PQ.top();
        PQ.pop();
    }
    printf("%d", ans);
}
