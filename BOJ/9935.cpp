#include <bits/stdc++.h>
using namespace std;
string S, T, result;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> S >> T;
    for (int i = 0; i < S.length(); i++) {
        result += S[i];
        if (result.length() >= T.length() && result.substr(result.length() - T.length(), T.length()) == T) {
            result.erase(result.end() - T.length(), result.end());
        }
    }
    cout << (!result.length() ? "FRULA" : result);
}