#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    for (int i = -N + 1;i < N;i++) {
        for (int j = abs(i);j > 0;j--) printf(" ");
        for (int j = 1;j <= N - abs(i);j++) printf("*");
        printf("\n");
    }
}