// sort
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0;i < n;i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for (int i : v) printf("%d\n", i);
}