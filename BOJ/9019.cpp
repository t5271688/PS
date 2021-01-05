#include <bits/stdc++.h>
using namespace std;
const int MOD = 10000;
typedef pair<int, char> P;
int T, A, B;
bool visited[10000];
P p[10000];
void bfs() {
    queue<int> Q;
    visited[A] = true;
    Q.push(A);
    while (!Q.empty()) {
        int curr = Q.front(); Q.pop();
        if (curr == B) {
            stack<char> ST;
            for (int i = curr; i != A; i = p[i].first) ST.push(p[i].second);
            while (!ST.empty()) printf("%c", ST.top()), ST.pop();
            printf("\n");
        }
        int D = (curr * 2) % MOD;
        int S = !curr ? 9999 : curr - 1;
        int L = curr * 10 % 10000 + curr / 1000;
        int R = curr % 10 * 1000 + curr / 10;
        if (!visited[D]) {
            visited[D] = true;
            p[D].first = curr;
            p[D].second = 'D';
            Q.push(D);
        }
        if (!visited[S]) {
            visited[S] = true;
            p[S].first = curr;
            p[S].second = 'S';
            Q.push(S);
        }
        if (!visited[L]) {
            visited[L] = true;
            p[L].first = curr;
            p[L].second = 'L';
            Q.push(L);
        }
        if (!visited[R]) {
            visited[R] = true;
            p[R].first = curr;
            p[R].second = 'R';
            Q.push(R);
        }
    }
}
int main() {
    for (scanf("%d", &T); T--;) {
        memset(visited, false, sizeof(visited));
        fill(p, p + 10000, P{ 0,' ' });
        scanf("%d%d", &A, &B);
        bfs();
    }
}