#include <bits/stdc++.h>
using namespace std;
int S[21][21], N, isteam[21];
vector<int> team;
int back_tracking(int idx = 1) {
    int ret = 1e9;
    if (idx == N + 1) {
        if (accumulate(isteam + 1, isteam + N + 1, 0)) return ret;
        ret = 0;
        for (int i = 1;i <= N;i++) for (int j = 1;j <= N;j++) if (isteam[i] == isteam[j]) ret += S[i][j] * isteam[i];
        return abs(ret);
    }
    isteam[idx] = 1;
    ret = min(ret, back_tracking(idx + 1));
    isteam[idx] = -1;
    ret = min(ret, back_tracking(idx + 1));
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) for (int j = 1;j <= N;j++) scanf("%d", &S[i][j]);
    printf("%d", back_tracking());
}