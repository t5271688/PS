/*
���� ���� ������ ���� �� �̺�Ž���ϸ� ���� ���� �� �ִ�.
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