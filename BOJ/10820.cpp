#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int u = 0, l = 0, d = 0, w = 0;
        for (auto e : s) {
            if (islower(e)) l++;
            if (isupper(e)) u++;
            if (isdigit(e)) d++;
            if (e == ' ') w++;
        }
        cout << l << " " << u << " " << d << " " << w << "\n";
    }
}