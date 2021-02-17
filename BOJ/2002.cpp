#include <bits/stdc++.h>
using namespace std;
int N, ans;
unordered_map<string, int> Map;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> N;
    for (int i = 0;i < N;i++) {
        cin >> str;
        Map[str] = i;
    }
    for (int i = 0;i < N;i++) {
        bool flag = true;
        cin >> str;
        for (auto e : Map) {
            if (e.second < Map.find(str)->second) {
                flag = false;
                break;
            }
        }
        Map.erase(str);
        ans += flag;
    }
    cout << N - ans;
}