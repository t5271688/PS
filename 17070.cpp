/*
Idea 1. ���̳��� ���α׷������� ����� �� ����
dp[y][x][dir]=�������� ���� (y,x)�̰� , �������� ������ ���°� dir�� ��, (N,N)�� ���� �� �� �ִ� ����Ǽ�
�̷��� ���̺��� �Ϲ�ȭ�ϰ� �������� �־��� ������ ������ § �� ��͸� ���� �������� ���� �� �ִ�.
*/
#include <bits/stdc++.h>
using namespace std;
#define horizontal 0//����
#define vertical 1//����
#define diagonal 2//�밢
int N;
int A[17][17];// �׸��� ���� A
int dp[17][17][3];// �޸������̼� ���̺� dp
int dyn(int y, int x, int dir) {// ���̳��� ���α׷��� ����Լ� dir 
    if (y < 1 || y > N || x < 1 || x > N) return 0;//������ ����� 0(�Ұ���)
    int& ret = dp[y][x][dir];
    if (ret != -1) return ret;// �̹� �������� �ֱ⿡ -1�� �ƴ϶�� �� ���� return
    if (y == N && x == N) return ret = 1;// (N,N)�� �����ϸ� Ƚ�� 1�̹Ƿ� 1 return
    ret = 0;//�ʱ�ȭ
    if (dir != vertical && !A[y][x + 1])  ret += dyn(y, x + 1, horizontal);// �������� ������������ ���η� ���� �� ���� ���ǰ� �� ���ǿ� �ǰ��� ���� ����.
    if (dir != horizontal && !A[y + 1][x])  ret += dyn(y + 1, x, vertical);// �����϶��� ����.
    if (!A[y][x + 1] && !A[y + 1][x] && !A[y + 1][x + 1]) ret += dyn(y + 1, x + 1, diagonal);//�밢������ ���� �� 3���� ���� �ƴϾ����
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%d", &A[i][j]);
    memset(dp, -1, sizeof(dp));//-1�� ���̺� �ʱ�ȭ
    printf("%d", dyn(1, 2, horizontal));// ����Լ��� dynamic programming
}