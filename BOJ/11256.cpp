#include <bits/stdc++.h>
using namespace std;
int J, N, a, b;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int ans = 0;
        vector<int> v;
        scanf("%d%d", &J, &N);
        for (int i = 0;i < N;i++) {
            scanf("%d%d", &a, &b);
            v.push_back(a * b);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (auto e : v) {
            ans++;
            J -= e;
            if (J <= 0) break;
        }
        printf("%d\n", ans);
    }
}