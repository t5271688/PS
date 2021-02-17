#include <bits/stdc++.h>
using namespace std;
int calc(int a, int b) { return a * 100 + b; }
int S, E, Q, ans;
char nickname[21];
unordered_map<string, bool> Map;
int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    scanf("%d:%d", &a, &b);
    S = calc(a, b);
    scanf("%d:%d", &a, &b);
    E = calc(a, b);
    scanf("%d:%d", &a, &b);
    Q = calc(a, b);
    while (~scanf("%d:%d", &a, &b)) {
        string nickname;
        cin >> nickname;
        int T = calc(a, b);
        if (T > Q) continue;
        if (T <= S) Map.insert({ nickname,true });
        if (T >= E && T <= Q) {
            if (Map.find(nickname) == Map.end()) continue;
            Map.erase(nickname);
            ans++;
        }
    }
    printf("%d", ans);
}