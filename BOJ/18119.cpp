#include <bits/stdc++.h>
using namespace std;
int N, M, known, q;
char s[1002], c;
int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    for (int i = 0;i < 26;i++) known |= (1 << i);
    vector<int> word(N);
    for (int i = 0;i < N;i++) {
        scanf("%s", s);
        for (int j = 0;s[j] != '\0';j++) word[i] |= (1 << (s[j] - 'a'));
    }
    while (M--) {
        int res = 0;
        scanf("%d %c", &q, &c);
        if (q == 2) known |= (1 << (c - 'a'));
        else known &= ~(1 << (c - 'a'));
        for (int i : word) res += ((known & i) == i);
        printf("%d\n", res);
    }
    return 0;
}