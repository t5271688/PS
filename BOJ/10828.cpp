#include <bits/stdc++.h>
using namespace std;
stack<int> st;
void solve(int N) {
    string op;
    int x;
    while (N--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            st.push(x);
            continue;
        }
        else if (op == "pop") {
            if (st.empty()) cout << -1;
            else {
                cout << st.top();
                st.pop();
            }
        }
        else if (op == "size") cout << st.size();
        else if (op == "empty") cout << st.empty();
        else if (op == "top") {
            if (st.empty()) cout << -1;
            else cout << st.top();
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