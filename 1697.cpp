#include <bits/stdc++.h>
using namespace std;
int N, K;
queue<int> Q;
const int MAX = 100001;
int visited[MAX];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> N >> K;
    Q.push(N);
    visited[N] = 1;
    while (!Q.empty()) {
        int S = Q.front();
        Q.pop();
        if (S == K) return !printf("%d", visited[S] - 1);;
        if (S + 1 < MAX && !visited[S + 1]) {
            Q.push(S + 1);
            visited[S + 1] = visited[S] + 1;
        }
        if (S - 1 >= 0 && !visited[S - 1]) {
            Q.push(S - 1);
            visited[S - 1] = visited[S] + 1;
        }
        if (S * 2 < MAX && !visited[S * 2]) {
            Q.push(S * 2);
            visited[S * 2] = visited[S] + 1;
        }
    }
}