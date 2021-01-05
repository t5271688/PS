#include <bits/stdc++.h>
using namespace std;
int w, h;//지도 넓이 w, 지도 높이 h
int A[51][51];//지도 배열
int dir[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1} };
//이동을 간단하게 표현하기 위한 방향 배열 dir, 각각 남 동 북 서 북서 남동 북동 남서
bool visited[51][51];//방문 체크배열 visited
bool isInside(int y, int x) {//지도 배열을 벗어나는지 체크할 함수 isInside(y,x)
    return y > 0 && y <= h && x > 0 && x <= w;
}
int dfs(int y, int x) {//dfs(y,x)
    visited[y][x] = true;//방문 체크
    for (int i = 0;i < 8;i++) {//8방향에 대해
        int ny = y + dir[i][0], nx = x + dir[i][1];//8방으로 새로운 좌표를 설정
        if (!isInside(ny, nx) || visited[ny][nx]) continue;//지도 밖이거나 방문한적 있으면 skip
        if (A[ny][nx]) dfs(ny, nx);//걸어갈 수 있는 땅이라면 dfs(ny,nx)
    }
    return 1;
}
int main() {
    while (true) {
        memset(visited, 0, sizeof(visited));//매 테스트케이스에 visited배열 초기화
        int ans = 0;//정답을 담을 변수 ans
        scanf("%d%d", &w, &h);//w,h 입력
        if (!w && !h) return 0;//만약 0,0 이면 종료
        for (int i = 1;i <= h;i++) for (int j = 1;j <= w;j++) scanf("%d", &A[i][j]);
        //지도 입력
        for (int i = 1;i <= h;i++)
            for (int j = 1;j <= w;j++)
                if (!visited[i][j] && A[i][j]) ans += dfs(i, j);
        //A[i][j]가 방문하지 않은 땅이면 dfs(i,j);
        printf("%d\n", ans);
    }
}