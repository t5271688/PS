/*
124³ª¶ó
*/
#include <bits/stdc++.h>
using namespace std;
string solution(int n) {
    vector<int> v;
    string answer = "";
    while (n) {
        if (!(n % 3)) {
            n -= 1;
            n /= 3;
            answer += '4';
        }
        else {
            answer += (n % 3) + '0';
            n /= 3;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}