#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    queue<int> Q[31];
    stack<int> st;
    int answer = 0;
    int size = board.size();
    for (int i = 0;i < size;i++) for (int j = 0;j < size;j++) if (board[j][i]) Q[i + 1].push(board[j][i]);
    for (int c : moves) {
        if (Q[c].empty()) continue;
        if (!st.empty() && st.top() == Q[c].front()) {
            st.pop();
            answer += 2;
        }
        else st.push(Q[c].front());
        Q[c].pop();
    }
    return answer;
}