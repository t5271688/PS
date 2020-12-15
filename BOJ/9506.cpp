/*
약수를 하나씩 구해주고, 약수의 합이 n과같으면 출력, 아니라면 is not perfect 출력
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    while (1) {
        scanf("%d", &n);
        if (n == -1) return 0;
        vector<int> v;
        int sum = 0;
        for (int i = 1;i <= n / 2;i++) {
            if (!(n % i)) {
                v.push_back(i);
                sum += i;
            }
        }
        if (sum == n) {
            sort(v.begin(), v.end());
            printf("%d = ", n);
            for (int i = 0;i < v.size();i++) {
                printf("%d", v[i]);
                if (i != v.size() - 1) printf(" + ");
            }
            printf("\n");
        }
        else printf("%d is NOT perfect.\n", n);
    }
}