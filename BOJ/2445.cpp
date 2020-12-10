#include <bits/stdc++.h>// 위쪽과 아래쪽 모양이 반대이기 때문에 절대값을 이용해 구현
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    for (int i = -N + 1;i < N;i++) {
        for (int j = 1;j <= N - abs(i);j++) printf("*");
        for (int j = abs(i) * 2;j > 0;j--) printf(" ");
        for (int j = 1;j <= N - abs(i);j++) printf("*");
        printf("\n");
    }
}