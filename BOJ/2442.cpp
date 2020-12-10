#include <bits/stdc++.h>//기본적인 별찍기
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) {
        for (int j = N - i;j > 0;j--) printf(" ");
        for (int j = 1;j <= 2 * i - 1;j++) printf("*");
        printf("\n");
    }
}