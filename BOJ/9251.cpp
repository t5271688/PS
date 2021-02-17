#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << '\n';
}