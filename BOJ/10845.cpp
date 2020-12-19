#include <bits/stdc++.h>
using namespace std;
queue<int> q;
void solve(int N) {
    int x;
    string op;
    while (N--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            q.push(x);
            continue;
        }
        else if (op == "pop") {
            if (q.empty()) cout << -1;
            else {
                cout << q.front();
                q.pop();
            }
        }
        else if (op == "size") cout << q.size();
        else if (op == "empty") cout << q.empty();
        else if (op == "front") {
            if (q.empty()) cout << -1;
            else cout << q.front();
        }
        else if (op == "back") {
            if (q.empty()) cout << -1;
            else cout << q.back();
        }
        cout << "\n";
    }
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    solve(N);
}