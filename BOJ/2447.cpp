#include <bits/stdc++.h>
using namespace std;
int N;
bool A[2188][2188];
void dnc(int y, int x, int n) {
    if (n == 1) {//기저 사례 : n==1 (크기가 1일때) 별을 찍음, subproblem solved
        A[y][x] = 1;
        return;
    }
    n /= 3;//sub problem의 크기가 n/3씩 줄어듬
    for (int i = 0;i < 3;i++)//가운데를 제외한 8방향에서 subproblem 호출
        for (int j = 0;j < 3;j++)
            if (i != 1 || j != 1)//가운데를 제외하고,
                dnc(y + (i * n), x + (j * n), n); //subproblem 호출
    /*
    dnc(y,x, n); 북서
    dnc(y,x+n,n) 북
    dnc(y,x+2*n,n) 북동
    dnc(y+n,x,n) 서, 가운데는 제외
    dnc(y+n,x+2*n,n) 동
    dnc(y+2*n,x,n) 남서
    dnc(y+2*n,x+n,n) 남
    dnc(y+2*n,x+2*n,n) 남동
    */
}
int main() {
    scanf("%d", &N);
    dnc(0, 0, N);// 분할 정복 재귀 함수
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) printf("%c", A[i][j] ? '*' : ' ');
        printf("\n");
    }
}