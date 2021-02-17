#include <bits/stdc++.h>
using namespace std;
int N, arr[1000], E;
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N;i++) scanf("%d", arr + i);
    sort(arr, arr + N);
    for (int i = 0;i < N;i++) {
        if (arr[i] > E + 1) return !printf("%d", E + 1);
        E += arr[i];
    }
    printf("%d", E + 1);
    return 0;
}