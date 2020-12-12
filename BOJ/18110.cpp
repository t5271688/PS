#include <bits/stdc++.h>//실수 연산을 하면 풀 수 있다.
using namespace std;
int n, sum;
vector<int> v;
double p = (double)15 / 100;
int main() {
    scanf("%d", &n);
    if (!n) return !printf("0");//n이 0이면 평균도 0
    int R = round((double)n * p);//round 활용
    for (int i = 1;i <= n;i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());//sort
    for (int i = 0;i < n;i++) if (i >= R && i < n - R) sum += v[i];//sum
    printf("%d", (int)round((double)sum / (n - 2 * R)));//divide and print
}