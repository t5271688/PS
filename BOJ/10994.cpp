#include <bits/stdc++.h>//바깥쪽부터 껍질을 그리는 재귀함수로 하여금 프랙탈을 그리게 식을 짬
using namespace std;
int a[500][500];
int N;
void rec(int n) {
    if (!n) return;//기저 사례
    int s = (N - n) * 2, e = 4 * n - 3 + s; //초기 N과 재귀단계 n을 이용해 offset설정
    for (int i = s;i < e;i++) a[s][i] = a[i][s] = a[e - 1][i] = a[i][e - 1] = 1;//겉 껍질을 그리게 함
    rec(n - 1);//재귀
}
int main() {
    scanf("%d", &N);
    rec(N);
    for (int i = 0;i < 4 * N - 3;i++) {
        for (int j = 0;j < 4 * N - 3;j++) printf("%c", a[i][j] ? '*' : ' ');//껍질이있는곳은 별, 아니면 공백
        printf("\n");
    }
}