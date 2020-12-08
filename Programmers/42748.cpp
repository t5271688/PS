#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> answer;
    int size = commands.size();
    for (int i = 0;i < size;i++) {
        for (int j = commands[i][0] - 1;j < commands[i][1];j++) pq.push(array[j]);
        while (--commands[i][2]) pq.pop();
        answer.emplace_back(pq.top());
        while (!pq.empty()) pq.pop();
    }
    return answer;
}