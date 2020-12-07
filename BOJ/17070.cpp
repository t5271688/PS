/*
Idea 1. 다이나믹 프로그래밍으로 경우의 수 세기
dp[y][x][dir]=파이프의 끝이 (y,x)이고 , 파이프가 놓여진 상태가 dir일 때, (N,N)에 도달 할 수 있는 경우의수
이렇게 테이블을 일반화하고 문제에서 주어진 내용을 식으로 짠 후 재귀를 돌면 가짓수를 구할 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;
#define horizontal 0//가로
#define vertical 1//세로
#define diagonal 2//대각
int N;
int A[17][17];// 그림의 상태 A
int dp[17][17][3];// 메모이제이션 테이블 dp
int dyn(int y, int x, int dir) {// 다이나믹 프로그래밍 재귀함수 dir 
    if (y < 1 || y > N || x < 1 || x > N) return 0;//범위를 벗어나면 0(불가능)
    int& ret = dp[y][x][dir];
    if (ret != -1) return ret;// 이미 계산된적이 있기에 -1이 아니라면 그 값을 return
    if (y == N && x == N) return ret = 1;// (N,N)에 도달하면 횟수 1이므로 1 return
    ret = 0;//초기화
    if (dir != vertical && !A[y][x + 1])  ret += dyn(y, x + 1, horizontal);// 수평으로 놓여있을때는 가로로 놓을 수 없는 조건과 벽 조건에 의거해 식을 쓴다.
    if (dir != horizontal && !A[y + 1][x])  ret += dyn(y + 1, x, vertical);// 수직일때도 같다.
    if (!A[y][x + 1] && !A[y + 1][x] && !A[y + 1][x + 1]) ret += dyn(y + 1, x + 1, diagonal);//대각선으로 놓을 때 3면이 벽이 아니어야함
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%d", &A[i][j]);
    memset(dp, -1, sizeof(dp));//-1로 테이블 초기화
    printf("%d", dyn(1, 2, horizontal));// 재귀함수로 dynamic programming
}