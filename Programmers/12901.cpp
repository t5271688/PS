#include <bits/stdc++.h>
using namespace std;
string day[7] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
int month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

string solution(int a, int b) {
    int n = 0;
    for (int i = 1;i < a;i++) n += month[i];
    string answer = day[(n + b) % 7];
    return answer;
}