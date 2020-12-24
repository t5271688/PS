#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9;
ll dp[101][10], ans;//dp[n][prev] = n�ڸ����̰�, leading number�� prev�� ��ܼ��� ����� ����� ��
int N;
ll dyn(int n, int prev) {
    if (n == 1) return 1;//n==1�ϋ�(���ڸ� �� �϶�)�� ��� ���� ��� ���̴�.(���� ���)
    ll& ret = dp[n][prev];
    if (ret != -1) return ret;
    ret = 0;
    ret += prev == 9 ? 0 : dyn(n - 1, prev + 1);//9�϶��� �����ϰ�� ���� ���� +1��ŭ ���̳��� prev�� ���� �� ����
    ret += prev == 0 ? 0 : dyn(n - 1, prev - 1);//0�϶��� �����ϰ�� ���� ���� -1��ŭ ���̳��� prev�� ���� �� ����
    return ret %= MOD;
}
int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));//�Ұ����� �������� -1������ �ʱ�ȭ
    for (int i = 1;i <= 9;i++) ans = (ans + dyn(N, i)) % MOD;//N�ڸ����̰�, i�� leading number�� ������ ��ܼ��� �߰�(N�ڸ� ���̸� 1~9�� leading number�� ����)
    printf("%lld", ans);
}