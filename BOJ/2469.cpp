/*
위에서부터 감춰진 라인의 바로 위까지 진행하고, 아래에서부터 감춰진라인의 바로 아래까지 진행한 후,
두 문자열의 차이를 통해 감춰진 라인을 만든다.
만약 불가능한 구조일 경우 x 출력
*/
#include <bits/stdc++.h>
using namespace std;
int k, n;
string s, e, ans;
bool unable;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> k >> n;
    vector<string> v(n);//string vector
    for (int i = 'A';i < 'A' + k;i++) s.push_back(i);
    cin >> e;
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;v[i][0] != '?';i++) for (int j = 0;j < k - 1;j++) if (v[i][j] == '-') swap(s[j], s[j + 1]);// 위에서부터
    for (int i = n - 1;v[i][0] != '?';i--) for (int j = 0;j < k - 1;j++) if (v[i][j] == '-') swap(e[j], e[j + 1]); //아래에서부터
    for (int i = 0;i < k - 1;i++) {
        if (s[i] == e[i]) ans.push_back('*');
        else if (s[i] == e[i + 1] && e[i] == s[i + 1]) {
            ans.push_back('-');
            swap(s[i], s[i + 1]);
        }
        else unable = true;
    }
    if (unable) for (int i = 0;i < k - 1;i++) cout << 'x';
    else cout << ans;
}