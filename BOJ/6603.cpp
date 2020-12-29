#include <bits/stdc++.h>
using namespace std;
int K;
vector<int> V;
vector<int> Choice;
void back_tracking(int idx = 0, int used = 0) {
    if (used == 6) {
        for (int i = 0; i < (int)Choice.size(); i++) printf("%d ", Choice[i]);
        printf("\n");
        return;
    }
    if (idx == (int)V.size()) return;
    Choice.push_back(V[idx]);
    back_tracking(idx + 1, used + 1);
    Choice.pop_back();
    back_tracking(idx + 1, used);
}
int main() {
    while (true) {
        scanf("%d", &K);
        if (!K) return 0;
        for (int i = 0; i < K; i++) {
            int n;
            scanf("%d", &n);
            V.emplace_back(n);
        }
        back_tracking();
        V.clear();
        printf("\n");
    }
}