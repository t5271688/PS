#include <bits/stdc++.h>//�� ���� ������ ������ ����Լ��� �׸��鼭 ����Ż ����
using namespace std;
int N;
bool a[6500][6500];
void rec(int n, int y, int x) {
    if (n == 3) {//���� ��� n==3�϶� �ﰢ�� ����
        a[y][x] = a[y + 1][x - 1] = a[y + 1][x + 1] = 1;
        for (int i = -2;i <= 2;i++) a[y + 2][x + i] = 1;
        return;
    }
    n /= 2;
    rec(n, y, x);//ũ�� n/2�� ���� �ﰢ��
    rec(n, y + n, x - n);//ũ�� n/2�� ���� �ﰢ��
    rec(n, y + n, x + n);//ũ�� n/2�� ������ �ﰢ��

}
int main() {
    scanf("%d", &N);
    rec(N, 0, N - 1);//��� ����
    for (int i = 0;i < N;i++) {//���
        for (int j = 0;j < 2 * N;j++) printf("%c", a[i][j] ? '*' : ' ');
        printf("\n");
    }

}