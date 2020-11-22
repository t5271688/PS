#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
queue<PI> Q;
int N, M, ans;
int A[1000][1000];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
bool isInside(int y, int x) {
	return y >= 0 && y < N&& x >= 0 && x < M;
}
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> A[i][j];
			if (A[i][j] == 1) Q.push({ i, j });
		}
	}
	while (!Q.empty()) {
		auto top = Q.front();
		Q.pop();
		int y = top.first, x = top.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (isInside(ny, nx) && !A[ny][nx]) {
				A[ny][nx] = A[y][x] + 1;
				Q.push({ ny, nx });
			}
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (!A[i][j]) return !printf("-1");;
			ans = max(ans, A[i][j]);
		}
	}
	cout << ans - 1;
}