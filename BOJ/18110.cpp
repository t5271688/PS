#include <bits/stdc++.h>//�Ǽ� ������ �ϸ� Ǯ �� �ִ�.
using namespace std;
int n, sum;
vector<int> v;
double p = (double)15 / 100;
int main() {
    scanf("%d", &n);
    if (!n) return !printf("0");//n�� 0�̸� ��յ� 0
    int R = round((double)n * p);//round Ȱ��
    for (int i = 1;i <= n;i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());//sort
    for (int i = 0;i < n;i++) if (i >= R && i < n - R) sum += v[i];//sum
    printf("%d", (int)round((double)sum / (n - 2 * R)));//divide and print
}