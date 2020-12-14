#include <bits/stdc++.h>
using namespace std;
int used[26];
vector<char> v;
int main() {
    string s;
    cin >> s;
    for (char c : s) used[toupper(c) - 'A']++;
    for (int i = 0;i < 26;i++) v.push_back('A' + i);
    sort(v.begin(), v.end(), [=](const char& A, const char& B) { return used[A - 'A'] < used[B - 'A']; });
    printf("%c", used[v[25] - 'A'] == used[v[24] - 'A'] ? '?' : v[25]);
}