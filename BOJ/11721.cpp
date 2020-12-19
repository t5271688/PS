#include <bits/stdc++.h>
using namespace std;
char s[102];
int main() {
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0;i < l;i++) {
        printf("%c", s[i]);
        if (i % 10 == 9) printf("\n");
    }
}