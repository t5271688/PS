/*
���� ������ ���� ������ ������
���� ������ Ƚ����ŭ ������ ǥ���ϰ� ���� ������ �ѷ��ش�
*/
#include <bits/stdc++.h>
using namespace std;
int n, a;
int used[10001];
int main() {
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        scanf("%d", &a);
        used[a]++;
    }
    for (int i = 0;i < 10001;i++) {
        while (used[i]--) printf("%d\n", i);
    }
}