#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vi::iterator vit;
vi v;
void postOrder(vit s, vit e) {
    if (e <= s) return;
    auto r = upper_bound(s + 1, e, *s);
    postOrder(s + 1, r);
    postOrder(r, e);
    printf("%d\n", *s);
}

int main() {
    int t;
    while (~scanf("%d", &t)) v.push_back(t);
    postOrder(v.begin(), v.end());
}