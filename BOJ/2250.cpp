/*
Idea 1. �� ��ȣ�� �ű�� ������ inorder traversal
= ���� ��ȸ�� ���� ��ȣ�� �ű� �� �ְڴ�.
Idea 2. inorder�� �� �� level ���� �ִ� �ּҰ� ����
Idea 3. ��Ʈ�� ������ �ִ��� �˾����� ��Ʈ�� ���� �������� �ʾҴ�
= ��� ��带 ������ �� �θ� ���� ���� ��Ʈ�� �Ͽ� Ž��
*/
#include <bits/stdc++.h>
using namespace std;
struct tree {//Ʈ�� ����ü
private:
    int lvmax[10001];//�� ������ �ִ밪
    int lvmin[10001];//�� ������ �ּҰ�
    int N;// ��� ����
    int num;// idx �ο��� ����
    struct node {
        int idx;//traversal�� ���� �Ű��� ��ġ
        int left;//�����ڽĳ��
        int right;//������ �ڽ� ���
        int parents;// �θ� ���
    };
    node nodes[10001];
public:
    tree(int n) :N(n) {
        num = 0;
        for (int i = 1;i <= N;i++) nodes[i].parents = -1;//��� �θ� -1�� �ʱ�ȭ(��Ʈ ã�� ����)
        for (int i = 1;i <= N;i++) {// �ִ� �ּ� �ʱ�ȭ
            lvmax[i] = -1e9;
            lvmin[i] = 1e9;
        }
    }
    void makeNode(int current, int l, int r) {//��� ����
        nodes[current].left = l;
        nodes[current].right = r;
        nodes[l].parents = nodes[r].parents = current;
    }
    void inorder(int current, int level = 1) {//���� ��ȸ(inorder traversal)
        if (current == -1) return;
        inorder(nodes[current].left, level + 1);
        nodes[current].idx = ++num;//idx�� ��ġ �ο�
        if (nodes[current].idx > lvmax[level]) lvmax[level] = nodes[current].idx;//�������� �ִ� �ּ� ����
        if (nodes[current].idx < lvmin[level]) lvmin[level] = nodes[current].idx;
        inorder(nodes[current].right, level + 1);
    }
    void solve() {
        int root, ans = -1, t = 0;
        for (int i = 1;i <= N;i++) {//��Ʈã��
            if (nodes[i].parents == -1) {
                root = i;
                break;
            }
        }
        inorder(root);//inorder traversal
        for (int i = 1;i <= N;i++) {//���������� �ִ��ּҰ��� ���� �ʺ� ���
            if (lvmax[i] == -1e9 && lvmin[i] == 1e9) break;
            if (ans < lvmax[i] - lvmin[i] + 1) {
                t = i;
                ans = lvmax[i] - lvmin[i] + 1;
            }
        }
        printf("%d %d", t, ans);
    }
};

int main() {
    int N;
    scanf("%d", &N);
    tree t(N);
    for (int i = 0;i < N;i++) {
        int c, l, r;
        scanf("%d%d%d", &c, &l, &r);
        t.makeNode(c, l, r);
    }
    t.solve();
}