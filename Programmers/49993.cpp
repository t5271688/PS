/*
스킬트리
*/
#include <bits/stdc++.h>
using namespace std;
vector<bool> able(26, true);
int req[26];
int solution(string skill, vector<string> skill_trees) {
    for (int i = 0;i < skill.size() - 1;i++) {
        able[skill[i + 1] - 'A'] = false;
        req[skill[i] - 'A'] = skill[i + 1] - 'A';
    }
    int answer = 0;
    for (auto s : skill_trees) {
        vector<bool> tmp = able;
        int ok = true;
        for (auto c : s) {
            if (!tmp[c - 'A']) {
                ok = false;
                break;
            }
            tmp[req[c - 'A']] = true;
        }
        answer += ok;
    }
    return answer;
}