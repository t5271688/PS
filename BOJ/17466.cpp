/*
��Ʈ������ �����ϸ� �Ź� p�� �����ָ� �ȴ�.
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