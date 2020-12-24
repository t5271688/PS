#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
string S[100001];
int main() {
    int N;
    cin >> N;
    vector<p> v(N);
    for (int i = 0;i < N;i++) {
        cin >> v[i].first >> S[i];
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    for (auto e : v) cout << e.first << " " << S[e.second] << "\n";
}