#include <bits/stdc++.h>
using namespace std;
char day[7][4] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }, n = 0;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 1;i < a;i++) n += month[i];
    printf("%s", day[(n + b) % 7]);
}