#include <bits/stdc++.h>
using namespace std;
char s[101];
int a[26];
int main() {
    scanf("%s", s);
    memset(a, -1, sizeof(a));
    for (int i = 0;s[i];i++) if (a[s[i] - 'a'] == -1) a[s[i] - 'a'] = i;
    for (int i = 0;i < 26;i++) printf("%d ", a[i]);
}