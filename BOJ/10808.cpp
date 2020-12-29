#include <bits/stdc++.h>
using namespace std;
char s[101];
int a[26];
int main() {
    scanf("%s", s);
    for (int i = 0;s[i];i++)  a[s[i] - 'a']++;
    for (int i = 0;i < 26;i++) printf("%d ", a[i]);
}