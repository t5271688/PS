/*
2�� �������ϰ�� ��Ʈ�� ��Ÿ���� Ȱ���� ��Ʈ�� �ϳ��̱� ������ ��Ʈ���� ���ش�
*/
#include <bits/stdc++.h>
using namespace std;
long long N;
int main() {
    scanf("%lld", &N);
    printf("%d", __builtin_popcountll(N) == 1 ? 1 : 0);
}