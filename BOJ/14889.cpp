/*
��Ʈ��ŷ ����Լ��� �������� �Ͽ���.
*/
#include <bits/stdc++.h>
using namespace std;
int S[21][21], N, isteam[21];//���ó����� �����ϴ�S�迭, i��°�ο��� ��������� ������ 1,-1���������� ������ ������ isteam �迭
int back_tracking(int idx = 1) {
    int ret = 1e9;
    if (idx == N + 1) {//��� �ο��� ��ġ �Ͽ��� ��,
        if (accumulate(isteam + 1, isteam + N + 1, 0)) return ret;//isteam�� �� ���� 0�� �ƴ϶�� N/2�� ���� �ƴϹǷ� �Ұ���
        ret = 0;
        for (int i = 1;i <= N;i++) for (int j = 1;j <= N;j++) if (isteam[i] == isteam[j]) ret += S[i][j] * isteam[i];// i��j�� ���� ���� ���, S[i][j]�� isteam�� ���� ���� ����
        return abs(ret);//���밪 ����
    }
    isteam[idx] = 1;//idx�� ��ŸƮ ���϶�
    ret = min(ret, back_tracking(idx + 1));//��Ʈ��ŷ
    isteam[idx] = -1;//idx�� ��ũ ���϶�
    ret = min(ret, back_tracking(idx + 1));//��Ʈ��ŷ
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) for (int j = 1;j <= N;j++) scanf("%d", &S[i][j]);
    printf("%d", back_tracking());//�Լ� ����
}