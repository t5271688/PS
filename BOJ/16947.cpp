/*
Idea 1. Bidirectional Graph���� Cycle ã��
���� �׷������� ����Ŭ�� ã�� ��, �湮�� ������ �ٽ� �湮�ϸ� ����Ŭ�� ����
�׷��� ������̱� ������ �Ϲ����� ������� �ϸ� �������� ����Ŭ�� ����
= ũ�Ⱑ 3�̻��� ����Ŭ�� ã���� ���ǹ��� ������

Idea 2. ����Ŭ�� ���ʿ��� ������ ���Ե��� �ʵ��� ��� ���� �ϱ�
DFS�� ������ �� �� �������� ��� ��η� �̵��ϴ��� ���(to �迭)
�̹� �湮�� ����(����Ŭ�� ����)�� �湮���� ��,to �迭�� �����ϸ� ����Ŭ Ž��

����Ŭ�� ã�� ��, ����Ŭ ��ü���� ����Ŭ�� �ƴ� ���������� �Ÿ��� BFS�� Ž��
DFS O(N) BFS O(N)
�ð����⵵ O(N)�� �ذ� ����
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 3001;
typedef vector<int> vi;
vi adj[MAX];// �׷����� ǥ���� ���� ����Ʈ
queue<int> Q;// BFS�� ����� queue
int visited[MAX], dist[MAX], to[MAX], N, u, v;//�湮�迭 visited, �Ÿ��迭 dist, ����Ŭ ������ �迭 to
bool DFS(int curr, int D) {//DFS 
    int ret;
    if (visited[curr]) {//�̹� �湮�� ������ ����̸�,
        if (D - dist[curr] >= 3) {//����Ŭ�� ũ�Ⱑ 3�̻�(����Ŭ�� ������ġ�� ������ġ�� �Ÿ����� 3�̻�)�̸�,
            for (int temp = to[curr];temp != curr;temp = to[temp]) visited[temp] = 2;//����Ŭ ���� �ݺ���(to �迭�� �����ϸ� ����Ŭ ����)
            visited[curr] = 2;//����Ŭ�� ���Ե� �������� 2�� üũ
            return true;//true ����
        }
        else return false;// �湮�� ���������� ����Ŭ�� ũ�Ⱑ 2�̸�(������ ����)�� ���� false ����
    }
    visited[curr] = 1;//�湮 üũ
    dist[curr] = D;// �Ÿ� ǥ��
    for (int next : adj[curr]) {//DFS �ݺ�
        to[curr] = next;// �� �������� ��� �������� ������ ���
        if (ret = DFS(next, D + 1)) return ret;//DFS���� true �����ϸ�(����Ŭ�� �����ϰ� �����ߴٸ�) �״�� true ����
    }
    return ret;//�� Ž������ ����Ŭ�� ã�� �������� false ����
}
void BFS() {//BFS
    while (!Q.empty()) {//����Ŭ�� ���Ե� �������κ��� �ٸ� ���������� �Ÿ� ���
        int top = Q.front();
        Q.pop();
        for (int next : adj[top]) {
            if (!visited[next]) {
                dist[next] = dist[top] + 1;
                visited[next] = true;
                Q.push(next);
            }
        }
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {//���� ����Ʈ �����ϱ�
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);//DFS ����
    for (int i = 1;i <= N;i++) {//DFS�Ϸ� ��, ����Ŭ�� ���Ե� ������ ��� ť�� �ְ� �Ÿ��� 0���� ����
        if (visited[i] == 2) {
            Q.push(i);
            dist[i] = 0;
        }
        else visited[i] = 0;//�� ����Ŭ �����̶�� �湮 �迭 �ʱ�ȭ
    }
    BFS();//BFS
    for (int i = 1;i <= N;i++) printf("%d ", dist[i]);
    return 0;
}