#include <bits/stdc++.h>
const int MAX_V = 1005;
using namespace std;
int main() {
    int T;
    for (scanf("%d", &T); T--;) {
        int cost[1005] = { 0 };// �� �ǹ� �Ǽ��� �ʿ��� �ð�
        long long tcost[1005] = { 0 };//�� �ǹ��� ���µ� �ʿ��� �ּ� �ð� 
        int D[1005] = { 0 };//������ Indegree
        vector<int> adj[MAX_V];//�׷���
        int N, K, W;
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; i++) scanf("%d", cost + i);
        for (int i = 1; i <= K; i++) {//���� ���� �Է� ������ Indegree ����
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            D[b]++;//indegree ++
        }
        scanf("%d", &W);
        queue<int> Q;
        for (int i = 1; i <= N; i++)
            if (D[i] == 0) {// Indegree�� 0�� ������ tcost=cost�̴�.
                tcost[i] = cost[i];
                Q.push(i);// Indegree�� 0�� ���� ť�� ����
            }
        for (int i = 1; i <= N; i++) {//������ ��� ������ ��������
            int curr = Q.front();//ť���� Indegree�� 0�� ������ ����ִ�.
            Q.pop();
            for (int next : adj[curr]) {//�� �������� ������� ������ tcost�� �����ϰ�
                tcost[next] = max(tcost[next], tcost[curr] + cost[next]);
                if (--D[next] == 0) Q.push(next);// Indegree�� ���ҽ�Ű�� 0�̸� ť�� ����
            }
        }
        printf("%lld\n", tcost[W]);
    }
    return 0;
}