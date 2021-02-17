#include <bits/stdc++.h>
using namespace std;
int N, M, num;
unordered_map<int, int> Map;
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        Map.insert({ num, num });
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        if (Map.find(num) == Map.end())
            printf("%d", 0);
        else
            printf("%d", 1);
        printf("\n");
    }
    return 0;
}
