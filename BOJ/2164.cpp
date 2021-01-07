#include <bits/stdc++.h>
using namespace std;
queue<int> Q;
int main() {
    int N, ans;
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) Q.push(i);
    while (1) {
        ans = Q.front();
        Q.pop();
        if (Q.empty()) break;
        Q.push(Q.front());
        Q.pop();
    }
    printf("%d", ans);
}