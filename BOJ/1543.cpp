#include <bits/stdc++.h>
using namespace std;
string S, T, result;
int ans, _min;
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin, S);
    getline(cin, T);
    for (int i = 0; i < S.length(); i++) {
        if (S.substr(i, T.length()) == T) {
            i += T.length() - 1;
            ans++;
        }
    }
    cout << ans;
}