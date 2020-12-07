#include <bits/stdc++.h>
using namespace std;
int t, ans;
int main() {
    int n, l;
    scanf("%d%d", &n, &l);
    while (++t) {
        bool flag = 0;
        int tmp = t;
        while (tmp) {
            flag += (tmp % 10 == l);
            tmp /= 10;
        }
        ans += !flag;
        if (ans == n) return !printf("%d", t);
    }
}