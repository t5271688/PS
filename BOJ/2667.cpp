#include <bits/stdc++.h>
using namespace std;
int N, cnt;
int A[26][26];
bool visited[26][26];
vector<int> ans;
int dir[4][2] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
bool isInside(int y, int x) { return y >= 1 && y <= N && x >= 1 && x <= N; };
int dfs(int y, int x) {
    int ret = 1;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dir[i][0], nx = x + dir[i][1];
        if (isInside(ny, nx) && A[ny][nx] && !visited[ny][nx]) ret += dfs(ny, nx);
    }
    return ret;
}
void solve() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%1d", &A[i][j]);
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
        if (!visited[i][j] && A[i][j]) {
            ans.push_back(dfs(i, j));
            cnt++;
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", cnt);
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
}
int main() {
    solve();
}