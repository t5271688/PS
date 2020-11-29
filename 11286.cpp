#include <bits/stdc++.h>
using namespace std;
int N, x;
struct cmp { bool operator()(int A, int B) { return abs(A) == abs(B) ? A > B:abs(A) > abs(B); } };
priority_queue<int, vector<int>, cmp > PQ;
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