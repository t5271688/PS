#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
bool F[MAX] = { 1, 1,0, };
int main()
{
    for (int i = 2; i < MAX; i++)
    {
        if (!F[i])
            for (int j = 2; j * i < MAX; j++)
                F[j * i] = true;
    }
    int N, a, ans = 0;
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%d", &a);
        ans += !F[a];
    }
    printf("%d", ans);
}