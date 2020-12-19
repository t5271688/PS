#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    for (int i = -N + 1;i < N;i++) {
        for (int j = N - abs(i) - 1;j > 0;j--) printf(" ");
        for (int j = 1;j <= abs(i) * 2 + 1;j++) printf("*");
        printf("\n");
    }
}