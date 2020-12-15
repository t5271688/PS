/*
다리를 지나는 트럭
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<P> q;
    int time = 1, last = 0;
    for (int i : truck_weights) {
        if (i > weight) {
            while (i > weight) {
                auto [t, w] = q.front();
                q.pop();
                time = t;
                weight += w;
            }
        }
        q.push({ max(time + bridge_length,last + 1),i });
        last = q.back().first;
        weight -= i;

    }
    return q.back().first;
}
int main() {
    cout << solution(100, 100, { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 });
}