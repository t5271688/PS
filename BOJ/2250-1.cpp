/*
Idea 1. �� ��ȣ�� �ű�� ������ inorder traversal
= ���� ��ȸ�� ���� ��ȣ�� �ű� �� �ְڴ�.
Idea 2. inorder�� �� �� level ���� �ִ� �ּҰ� ����
Idea 3. ��Ʈ�� ������ �ִ��� �˾����� ��Ʈ�� ���� �������� �ʾҴ�
= ��� ��带 ������ �� �θ� ���� ���� ��Ʈ�� �Ͽ� Ž��
*/
#include <bits/stdc++.h>
using namespace std;
int lvmax[10001];//���� �ִ밪
int lvmin[10001];//���� �ּҰ�
int parents[10001];//�θ� ���
int l[10001];// ���� �ڽ� ���
int r[10001];// ������ �ڽ� ���
int idx[10001];// traversal�� ���� �Ű��� ����� ���ȣ
int max_depth, num;// �ִ� ���̿� ��ȣ �ű拚 ����� num
void inorder(int current, int depth = 1) {//inorder traversal 
    if (current == -1) return;
    max_depth = max(max_depth, depth);//�ִ� ���� ���
    inorder(l[current], depth + 1);
    idx[current] = ++num;//idx�� ��ȣ �ο�
    if (idx[current] > lvmax[depth]) lvmax[depth] = idx[current];//�ִ� �ּ� ����
    if (idx[current] < lvmin[depth]) lvmin[depth] = idx[current];
    inorder(r[current], depth + 1);
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        int c;
        scanf("%d", &c);
        scanf("%d%d", &l[c], &r[c]);// �ڽ�ã�� 
        parents[l[c]] = parents[r[c]] = c;//�θ� ã��
    }
    int root, ans = -1, t = 0;
    for (int i = 1;i <= N;i++) {
        if (!parents[i]) root = i;//�θ� ���ٸ� ��Ʈ
        lvmax[i] = -1e9;//�ִ� �ּ� �ʱ�ȭ
        lvmin[i] = 1e9;
    }
    inorder(root);//inorder traversal
    for (int i = 1;i <= max_depth;i++) {//�ִ� ���̱��� �ʺ� Ž��
        if (ans < lvmax[i] - lvmin[i] + 1) {
            t = i;
            ans = lvmax[i] - lvmin[i] + 1;
        }
    }
    printf("%d %d", t, ans);
}