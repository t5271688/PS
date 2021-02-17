#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int dist(const P& A, const P& B) {
    return abs(A.first - B.first) + abs(A.second - B.second);
}
vector<P> H;
vector<P> S;
vector<int> C;
int N, M, t;
int back_tracking(int idx = 0) {
    int ret = 2e9;
    if (idx > S.size()) return ret;
    if (C.size() == M) {
        ret = 0;
        for (int i = 0;i < H.size();i++) {
            int d = 2e9;
            for (int j = 0;j < C.size();j++) d = min(d, dist(H[i], S[C[j]]));
            ret += d;
        }
        return ret;
    }
    C.push_back(idx);
    ret = min(ret, back_tracking(idx + 1));
    C.pop_back();
    ret = min(ret, back_tracking(idx + 1));
    return ret;
}
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            scanf("%d", &t);
            if (t == 1) H.push_back({ i,j });
            if (t == 2) S.push_back({ i,j });
        }
    }
    printf("%d", back_tracking());
}