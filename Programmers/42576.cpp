#include <bits/stdc++.h>
using namespace std;
unordered_multimap<string, int> mm;
string solution(vector<string> participant, vector<string> completion) {
    int i = 0;
    for (string s : participant) mm.insert({ s,++i });
    for (string s : completion) mm.erase(mm.find(s));
    string answer = mm.begin()->first;
    return answer;
}