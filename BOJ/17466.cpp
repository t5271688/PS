/*
팩트리얼을 동작하며 매번 p를 나눠주면 된다.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, P, S = 1;
int main() {
    scanf("%lld%lld", &N, &P);
    for (int i = 1;i <= N;i++) {
        S *= i;
        S %= P;
    }
    printf("%d", S);
}