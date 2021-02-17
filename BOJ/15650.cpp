#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> c;
void back_Tracking(int n = 0) {
    if (n == N) {
        if (c.size() == M) {
            for (int e : c) printf("%d ", e + 1);
            printf("\n");
            return;
        }
        return;
    }
    c.push_back(n);
    back_Tracking(n + 1);
    c.pop_back();
    back_Tracking(n + 1);
}
int main() {
    scanf("%d%d", &N, &M);
    back_Tracking();
}