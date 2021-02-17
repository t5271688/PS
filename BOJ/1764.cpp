#include <bits/stdc++.h>
using namespace std;
int N, M;
string str;
unordered_map<string, int> Map;
vector<string> ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        Map[str] = i;
    }
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (Map.count(str)) ans.push_back(str);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (string s : ans) cout << s << '\n';
    return 0;
}