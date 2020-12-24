#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;
int dp[1001][10], ans; // dp[n][prev] = n�ڸ����̰�, leading number�� prev�� ���������� ����� ����� ��
int dyn(int n, int prev) {
    if (n == 1) return 1;//n==1�ϋ�(���ڸ� �� �϶�)�� ��� ���� ������ ���̴�.(���� ���)
    int& ret = dp[n][prev];
    if (ret) return ret;
    for (int i = prev;i <= 9;i++) ret = (ret + dyn(n - 1, i)) % MOD;//�ڸ����� n-1�̰�, ������ leading number �̻��� prev�� ���� ������ ���� ���� ����
    return ret;
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0;i <= 9;i++) ans = (ans + dyn(N, i)) % MOD;//N�ڸ����̰�, i�� leading number�� ������ ���������� �߰�(N�ڸ� ���̸� 0~9�� leading number�� ����)
    printf("%d", ans);
}