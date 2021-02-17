#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int visited[MAX];
int from[MAX];
queue<int> Q;
vector<int> ans;
int N, K;
int main() {
    scanf("%d%d", &N, &K);
    Q.push(N);
    visited[N] = 1;
    from[N] = -1;
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        if (curr == K) {
            printf("%d\n", visited[curr] - 1);
            for (int i = curr;i != -1;i = from[i]) ans.push_back(i);
            reverse(ans.begin(), ans.end());
            for (auto e : ans) printf("%d ", e);
            return 0;
        }
        if (curr + 1 < MAX && !visited[curr + 1]) {
            visited[curr + 1] = visited[curr] + 1;
            from[curr + 1] = curr;
            Q.push(curr + 1);
        }
        if (curr * 2 < MAX && !visited[curr * 2]) {
            visited[curr * 2] = visited[curr] + 1;
            from[curr * 2] = curr;
            Q.push(curr * 2);
        }
        if (curr - 1 >= 0 && !visited[curr - 1]) {
            visited[curr - 1] = visited[curr] + 1;
            from[curr - 1] = curr;
            Q.push(curr - 1);
        }
    }
}