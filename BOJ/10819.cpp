#include <bits/stdc++.h>
using namespace std;
int N, ans;
int main() {
    scanf("%d", &N);
    vector<int> v(N);
    for (int i = 0;i < N;i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    do {
        vector<int> t;
        adjacent_difference(v.begin(), v.end(), back_inserter(t));
        ans = max(ans, accumulate(t.begin() + 1, t.end(), 0, [](const int& A, const int& B) {return abs(A) + abs(B);}));
    } while (next_permutation(v.begin(), v.end()));
    printf("%d", ans);
}