/*
수가 많기 때문에 정렬 후 이분탐색하면 답을 구할 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0;i < n;i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    scanf("%d", &m);
    for (int i = 0;i < m;i++) {
        int t;
        scanf("%d", &t);
        printf("%d\n", binary_search(v.begin(), v.end(), t));
    }
}