#include <bits/stdc++.h>//�Ǻ� N�� �ð���ŭ t�迭�� n���� ������� ä��� �ȴ�.
using namespace std;
int N, Q, cnt;
int T[10001];
int main() {
    scanf("%d%d", &N, &Q);
    for (int i = 1;i <= N;i++) {
        int t;
        scanf("%d", &t);
        while (t--) T[cnt++] = i;
    }
    for (int i = 0;i < Q;i++) {
        int q;
        scanf("%d", &q);
        printf("%d\n", T[q]);
    }
}