#include <bits/stdc++.h>
using namespace std;
int N;
bool A[2188][2188];
void dnc(int y, int x, int n) {
    if (n == 1) {//���� ��� : n==1 (ũ�Ⱑ 1�϶�) ���� ����, subproblem solved
        A[y][x] = 1;
        return;
    }
    n /= 3;//sub problem�� ũ�Ⱑ n/3�� �پ��
    for (int i = 0;i < 3;i++)//����� ������ 8���⿡�� subproblem ȣ��
        for (int j = 0;j < 3;j++)
            if (i != 1 || j != 1)//����� �����ϰ�,
                dnc(y + (i * n), x + (j * n), n); //subproblem ȣ��
    /*
    dnc(y,x, n); �ϼ�
    dnc(y,x+n,n) ��
    dnc(y,x+2*n,n) �ϵ�
    dnc(y+n,x,n) ��, ����� ����
    dnc(y+n,x+2*n,n) ��
    dnc(y+2*n,x,n) ����
    dnc(y+2*n,x+n,n) ��
    dnc(y+2*n,x+2*n,n) ����
    */
}
int main() {
    scanf("%d", &N);
    dnc(0, 0, N);// ���� ���� ��� �Լ�
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) printf("%c", A[i][j] ? '*' : ' ');
        printf("\n");
    }
}