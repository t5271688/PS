#include <bits/stdc++.h>
using namespace std;
string str;
int len;
int main() {
    cin >> str;
    int len = str.length();
    list<char> L;
    for (int i = 0; i < len; i++) L.push_back(str[i]);
    auto C = L.end();
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        string op;
        cin >> op;
        if (op[0] == 'P') {
            string T;
            cin >> T;
            L.insert(C, T[0]);
        }
        else if (op[0] == 'L') {
            if (C != L.begin())
                C--;
        }
        else if (op[0] == 'D') {
            if (C != L.end())
                C++;
        }
        else {
            if (C != L.begin()) {
                C--;
                C = L.erase(C);
            }
        }
    }
    for (const auto& e : L) cout << e;
}