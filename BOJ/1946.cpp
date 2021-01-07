#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
vector<P> V;
int T, N;
int main() {
    scanf("%d", &T);
    while (T--) {
        int mina = 1e9, minb = 1e9, cnt = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            V.push_back({ a,b });
        }
        sort(V.begin(), V.end());
        for (int i = 0; i < N; i++) {
            if (V[i].first <= mina || V[i].second <= minb) {
                cnt++;
                mina = min(mina, V[i].first);
                minb = min(minb, V[i].second);
            }
        }
        printf("%d\n", cnt);
        V.clear();
    }
}