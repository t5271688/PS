#include <bits/stdc++.h>
using namespace std;
int N, x;
priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>> max_heap;
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%d", &x);
        if (i % 2) min_heap.push(x);
        else max_heap.push(x);
        if (!min_heap.empty() && min_heap.top() < max_heap.top()) {
            int a = max_heap.top(), b = min_heap.top();
            max_heap.pop();
            min_heap.pop();
            max_heap.push(b);
            min_heap.push(a);
        }
        printf("%d\n", max_heap.top());
    }
    return 0;
}