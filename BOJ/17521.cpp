#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<int> q;

int main() {
    int n, s;
    ll w, c = 0;
    scanf("%d%lld", &n, &w);
    for (int i = 0;i < n;i++) {
        scanf("%d", &s);
        q.push(s);
    }
    while (1) {
        int now = q.front();
        q.pop();
        if (q.empty()) {
            w += c * now;
            break;
        }
        if (now > q.front()) {
            w += c * now;
            c = 0;
        }
        else if (now < q.front()) {
            c += w / now;
            w %= now;
        }
    }
    printf("%lld", w);
}