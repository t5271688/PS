/*
수의 개수는 많고 범위는 작으니
수가 등장한 횟수만큼 변수에 표시하고 작은 수부터 뿌려준다
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