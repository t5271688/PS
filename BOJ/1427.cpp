#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
    int n;
    while (~scanf("%1d", &n)) v.push_back(n);
    sort(v.begin(), v.end(), greater<int>());
    for (auto e : v) printf("%d", e);
}