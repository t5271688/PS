/*
���� ���� ������ ���� �� �̺�Ž���ϸ� ���� ���� �� �ִ�.
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
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