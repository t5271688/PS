#include <bits/stdc++.h>
using namespace std;
int N;
deque<int> DQ;
void solve(int N) {
    int x;
    string op;
    while (N--) {
        cin >> op;
        if (op == "push_back") {
            cin >> x;
            DQ.push_back(x);
            continue;
        }
        else if (op == "push_front") {
            cin >> x;
            DQ.push_front(x);
            continue;
        }
        else if (op == "pop_front") {
            if (DQ.empty()) cout << -1;
            else {
                cout << DQ.front();
                DQ.pop_front();
            }
        }
        else if (op == "pop_back") {
            if (DQ.empty()) cout << -1;
            else {
                cout << DQ.back();
                DQ.pop_back();
            }
        }
        else if (op == "size") cout << DQ.size();
        else if (op == "empty") cout << DQ.empty();
        else if (op == "front") {
            if (DQ.empty()) cout << -1;
            else cout << DQ.front();
        }
        else if (op == "back") {
            if (DQ.empty()) cout << -1;
            else cout << DQ.back();
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