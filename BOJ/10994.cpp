#include <bits/stdc++.h>//�ٱ��ʺ��� ������ �׸��� ����Լ��� �Ͽ��� ����Ż�� �׸��� ���� «
using namespace std;
int a[500][500];
int N;
void rec(int n) {
    if (!n) return;//���� ���
    int s = (N - n) * 2, e = 4 * n - 3 + s; //�ʱ� N�� ��ʹܰ� n�� �̿��� offset����
    for (int i = s;i < e;i++) a[s][i] = a[i][s] = a[e - 1][i] = a[i][e - 1] = 1;//�� ������ �׸��� ��
    rec(n - 1);//���
}
int main() {
    scanf("%d", &N);
    rec(N);
    for (int i = 0;i < 4 * N - 3;i++) {
        for (int j = 0;j < 4 * N - 3;j++) printf("%c", a[i][j] ? '*' : ' ');//�������ִ°��� ��, �ƴϸ� ����
        printf("\n");
    }
}