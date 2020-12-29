#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
ll ans;
int N;
int A[100001];
p B[100001];
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N;i++) scanf("%d", &A[i]);
    for (int i = 0;i < N;i++) {
        scanf("%d", &B[i].first);
        B[i].second = i;
    }
    sort(B, B + N);
    for (int i = 0;i < N;i++) ans += A[B[i].second] + B[i].first * i;
    printf("%lld", ans);
}