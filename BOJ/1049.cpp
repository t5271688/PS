/*
������ ������ ���� �θ� ������ �� ä���, �ƴ϶�� �������� ����ִ¸�ŭ �� ��,
�������� �������� ä��°Ͱ� ������ ä��°� �� �Ѱ����� ����
*/
#include <bits/stdc++.h>
using namespace std;
int n, m, min1 = 1e9, min2 = 1e9;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0;i < m;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        min1 = min(min1, a);
        min2 = min(min2, b);
    }
    printf("%d", min1 >= min2 * 6 ? min2 * n : n / 6 * min1 + min(min1, n % 6 * min2));
}