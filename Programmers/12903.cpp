/*
��� ���� ��������
*/
#include <bits/stdc++.h>
using namespace std;
string solution(string s) {
    string answer = "";
    if (s.length() % 2) return answer = answer + s[s.length() / 2];
    else return answer = answer + s[s.length() / 2 - 1] + s[s.length() / 2];
}