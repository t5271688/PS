#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> v;
int main() {
    cin >> s;
    for (int i = 0;i < s.size();i++) v.push_back(s.substr(i, s.size() - i));
    sort(v.begin(), v.end());
    for (auto e : v) cout << e << "\n";
}