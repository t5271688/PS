#include <bits/stdc++.h>
using namespace std;
int N, x;
priority_queue<int, vector<int>, greater<int>> PQ;
int main() {
    for (scanf("%d", &N);N--;) {
        scanf("%d", &x);
        if (!x) {
            if (PQ.empty()) printf("0\n");
            else {
                printf("%d\n", PQ.top());
                PQ.pop();
            }
        }
        else PQ.push(x);
    }
    return 0;
}