#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        bool able = true;
        cin >> N;
        vector<string> str(N);
        for (int i = 0;i < N;i++) cin >> str[i];
        sort(str.begin(), str.end());
        for (int i = 0;i < N - 1;i++) {
            if (str[i][0] != str[i + 1][0]) continue;
            if (str[i].find(str[i + 1]) == string::npos && str[i + 1].find(str[i]) == string::npos) continue;
            able = false;
        }
        cout << (able ? "YES" : "NO") << '\n';
    }
}