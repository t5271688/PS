#include <bits/stdc++.h>//악보 N의 시간만큼 t배열을 n으로 순서대로 채우면 된다.
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