#include <bits/stdc++.h>
using namespace std;
char s[101][101];
int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", s[0]);
    for (int i = 1;i < N;i++) {
        scanf("%s", s[i]);
        if (s[0][0] != s[i][0]) return !printf("0");
    }
    printf("1");
}