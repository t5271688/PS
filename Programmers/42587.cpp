/*
«¡∏∞≈Õ
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, bool> P;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<P> q;
    vector<int>& p = priorities;
    for (int i = 0;i < p.size();i++) q.push({ p[i],i == location });
    sort(p.begin(), p.end());
    while (!q.empty()) {
        auto [x, f] = q.front();
        q.pop();
        if (p.back() == x) {
            p.pop_back();
            answer++;
            if (f) return answer;
        }
        else q.push({ x,f });
    }
}