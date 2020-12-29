#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (auto& e : s) {
        if (isupper(e)) e = (e - 'A' + 13) % 26 + 'A';
        if (islower(e)) e = (e - 'a' + 13) % 26 + 'a';
    }
    cout << s;
}