#include <bits/stdc++.h>
using namespace std;
int N, S;
vector<int> v;
int A[20];
int back_tracking(int idx = 0) {
    if (idx == N) {
        if (v.empty()) return 0;
        return accumulate(v.begin(), v.end(), 0) == S ? 1 : 0;
    }
    int ret = 0;
    v.push_back(A[idx]);
    ret += back_tracking(idx + 1);
    v.pop_back();
    ret += back_tracking(idx + 1);
    return ret;
}
int main() {
    scanf("%d%d", &N, &S);
    for (int i = 0;i < N;i++) scanf("%d", &A[i]);
    printf("%d", back_tracking());
}