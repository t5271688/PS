#include <bits/stdc++.h>
using namespace std;
const int offset = 60000;
int a, b, t;
int w[31];
int dp[120001][31];
int dyn(int weight, int idx) {
    if (weight == offset)
        return 1;
    if (idx > a)
        return 0;

    int& ret = dp[weight][idx];
    if (ret != -1)
        return ret;
    ret = 0;
    ret = dyn(weight - w[idx], idx + 1);
    ret = max(ret, dyn(weight, idx + 1));
    ret = max(ret, dyn(weight + w[idx], idx + 1));
    return ret;
}

int main() {
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) scanf("%d", &w[i]);
    scanf("%d", &b);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= b; i++) {
        scanf("%d", &t);
        printf("%c", dyn(offset + t, 1) ? 'Y' : 'N');
        if (i != b) printf(" ");
    }
    return 0;

}