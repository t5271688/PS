/*
2의 제곱수일경우 비트로 나타내면 활성된 비트가 하나이기 때문에 비트수를 세준다
*/
#include <bits/stdc++.h>
using namespace std;
long long N;
int main() {
    scanf("%lld", &N);
    printf("%d", __builtin_popcountll(N) == 1 ? 1 : 0);
}