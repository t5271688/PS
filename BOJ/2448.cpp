#include <bits/stdc++.h>//위 왼쪽 오른쪽 순으로 재귀함수를 그리면서 프랙탈 형성
using namespace std;
int N;
bool a[6500][6500];
void rec(int n, int y, int x) {
    if (n == 3) {//기저 사례 n==3일때 삼각형 형성
        a[y][x] = a[y + 1][x - 1] = a[y + 1][x + 1] = 1;
        for (int i = -2;i <= 2;i++) a[y + 2][x + i] = 1;
        return;
    }
    n /= 2;
    rec(n, y, x);//크기 n/2인 위쪽 삼각형
    rec(n, y + n, x - n);//크기 n/2인 왼쪽 삼각형
    rec(n, y + n, x + n);//크기 n/2인 오른쪽 삼각형

}
int main() {
    scanf("%d", &N);
    rec(N, 0, N - 1);//재귀 시작
    for (int i = 0;i < N;i++) {//출력
        for (int j = 0;j < 2 * N;j++) printf("%c", a[i][j] ? '*' : ' ');
        printf("\n");
    }

}