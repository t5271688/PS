#include <bits/stdc++.h>//바깥쪽부터 껍질을 그리는 재귀함수로 하여금 프랙탈을 그리게 식을 짬
using namespace std;
bool a[3000][3000];
int h[11], H;//h[i]= 단계별 높이, H= 최대 높이
int N;
void rec(int n, int y) {
    if (!n) return;//기저 사례
    int t = h[n - 1] * 2 - 1;//높이 보정 t=h[n-1]*2-1=h[n]-2;
    if (n % 2) {// 홀수 모양일 때,
        a[y][H] = 1;// 삼각형의 윗꼭지점 (모든 삼각형의 중간 꼭지점의 x좌표가 H이다)
        for (int i = 1;i <= t;i++) a[y + i][H + i] = a[y + i][H - i] = 1;// 꼭지점으로부터 한칸씩 내려가며 테두리 형성
        for (int i = -t - 1;i <= t + 1;i++) a[y + t + 1][H + i] = 1;//바닥 형성
    }
    else {// 짝수 모양일 때,
        a[y][H] = 1;// 삼각형의 아래 꼭지점
        for (int i = 1;i <= t;i++) a[y - i][H + i] = a[y - i][H - i] = 1;// 한칸씩 올라가며 테두리 형성
        for (int i = -t - 1;i <= t + 1;i++) a[y - t - 1][H + i] = 1;// 천장 형성
    }
    rec(n - 1, y + (n % 2 ? t : -t));// 껍질안에있는 가장 큰 삼각형의 위/아래 꼭지점의 y좌표를 잡아주며 재귀
}
int main() {
    for (int i = 1;i <= 10;i++) h[i] = (1 << i) - 1;
    scanf("%d", &N);
    H = h[N];
    rec(N, N % 2 ? 1 : H);
    for (int i = 1;i <= H;i++) {// 처음에는 Hx2*H-1 직사각형의 공백과 별을찍었지만 출력형식이 잘못됨. 삼각형의 범위까지만 출력하게 출력문 수정
        if (N % 2)for (int j = 1;j <= H - 1 + i;j++) printf("%c", a[i][j] ? '*' : ' ');// 홀수형 삼각형
        else for (int j = 1;j <= 2 * H - i;j++) printf("%c", a[i][j] ? '*' : ' ');// 짝수형 삼각형
        printf("\n");
    }
}