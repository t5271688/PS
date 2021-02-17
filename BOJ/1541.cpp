#include <bits/stdc++.h>
using namespace std;
string str;
int ans;
int main() {
    cin >> str;
    string sub = "";
    bool flag = true;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '+' && str[i] != '-') sub.push_back(str[i]);
        else {
            if (flag) {
                ans += stoi(sub);
                sub = "";
            }
            else {
                ans -= stoi(sub);
                sub = "";
            }
        }
        if (str[i] == '-') flag = false;
    }
    if (flag) {
        ans += stoi(sub);
        sub = "";
    }
    else {
        ans -= stoi(sub);
        sub = "";
    }
    cout << ans;
}