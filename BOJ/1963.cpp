#include <bits/stdc++.h>
using namespace std;
bool NP[10000] = { 1,1,0, };
int visited[10000];
int make_Num(int a, int b, int c, int d) {
    return a * 1000 + b * 100 + c * 10 + d;
}
int T;
int main() {
    for (int i = 2;i <= sqrt(9999);i++) {
        if (!NP[i]) for (int j = 2;i * j <= 9999;j++) NP[i * j] = true;
    }
    cin >> T;
    while (T--) {
        queue<int> Q;
        int S, T, ans = 0;
        cin >> S >> T;
        Q.push(S);
        visited[S] = 1;
        while (!Q.empty()) {
            int top = Q.front();
            Q.pop();
            if (top == T) {
                ans = visited[top] - 1;
                cout << ans << "\n";
                ans++;
                break;
            }
            int a = top / 1000, b = top % 1000 / 100, c = top % 100 / 10, d = top % 10;
            for (int i = 1;i < 10;i++) {
                if (i == a) continue;
                int curr = make_Num(i, b, c, d);
                if (visited[curr]) continue;
                if (!NP[curr]) {
                    Q.push(curr);
                    visited[curr] = visited[top] + 1;
                }
            }
            for (int i = 0;i < 10;i++) {
                if (i == b) continue;
                int curr = make_Num(a, i, c, d);
                if (visited[curr]) continue;
                if (!NP[curr]) {
                    Q.push(curr);
                    visited[curr] = visited[top] + 1;
                }
            }
            for (int i = 0;i < 10;i++) {
                if (i == c) continue;
                int curr = make_Num(a, b, i, d);
                if (visited[curr]) continue;
                if (!NP[curr]) {
                    Q.push(curr);
                    visited[curr] = visited[top] + 1;
                }
            }
            for (int i = 0;i < 10;i++) {
                if (i == d) continue;
                int curr = make_Num(a, b, c, i);
                if (visited[curr]) continue;
                if (!NP[curr]) {
                    Q.push(curr);
                    visited[curr] = visited[top] + 1;
                }
            }
        }
        if (!ans) cout << "Impossible" << "\n";
        fill(visited, visited + 10000, 0);
    }
}