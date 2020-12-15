/*
«¡∏∞≈Õ
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, bool> P;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<P> q;
    for (int i = 0;i < priorities.size();i++) q.push({ priorities[i],i == location });
    sort(priorities.begin(), priorities.end());
    while (!q.empty()) {
        auto [x, f] = q.front();
        q.pop();
        if (priorities.back() == x) {
            priorities.pop_back();
            answer++;
            if (f) return answer;
        }
        else q.push({ x,f });
    }
}