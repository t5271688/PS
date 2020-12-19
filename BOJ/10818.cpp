#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0;i < n;i++) scanf("%d", &v[i]);
    printf("%d %d", *min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()));
}