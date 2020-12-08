#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> answers) {
    int o1[5] = { 1,2,3,4,5 };
    int o2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int o3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> answer;
    int a = 0, b = 0, c = 0, size = answers.size();
    for (int i = 0;i < size;i++) {
        a += o1[i % 5] == answers[i];
        b += o2[i % 8] == answers[i];
        c += o3[i % 10] == answers[i];
    }
    int _max = max({ a,b,c });
    if (a == _max) answer.emplace_back(1);
    if (b == _max) answer.emplace_back(2);
    if (c == _max) answer.emplace_back(3);
    return answer;
}