/*
���������� ������ ������ �ٷ� ������ �����ϰ�, �Ʒ��������� ������������ �ٷ� �Ʒ����� ������ ��,
�� ���ڿ��� ���̸� ���� ������ ������ �����.
���� �Ұ����� ������ ��� x ���
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
    for (int i = 0;v[i][0] != '?';i++) for (int j = 0;j < k - 1;j++) if (v[i][j] == '-') swap(s[j], s[j + 1]);// ����������
    for (int i = n - 1;v[i][0] != '?';i--) for (int j = 0;j < k - 1;j++) if (v[i][j] == '-') swap(e[j], e[j + 1]); //�Ʒ���������
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