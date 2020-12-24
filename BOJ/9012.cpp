#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
    cin >> T;
    while (T--) {
        stack<char> st;
        string str;
        cin >> str;
        for (auto e : str) {
            if (e == '(' || st.empty()) st.push(e);
            else if (st.top() == '(') st.pop();
        }
        cout << (st.empty() ? "YES" : "NO") << "\n";
    }
}