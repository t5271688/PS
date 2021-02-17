#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> c;
bool used[9];
void back_Tracking(int n = 1) {
    if (c.size() == M) {
        for (int e : c) printf("%d ", e);
        printf("\n");
        return;
    }
    for (int i = 1;i <= N;i++) {
        if (!used[i]) {
            used[i] = true;
            c.push_back(i);
            back_Tracking(n + 1);
            c.pop_back();
            used[i] = false;
        }
    }
}
int main() {
    scanf("%d%d", &N, &M);
    back_Tracking();
}