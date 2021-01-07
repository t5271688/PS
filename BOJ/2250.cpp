/*
Idea 1. 행 번호를 매기는 순서가 inorder traversal
= 중위 순회를 돌면 번호를 매길 수 있겠다.
Idea 2. inorder를 돌 때 level 마다 최대 최소값 관리
Idea 3. 루트가 정해져 있는줄 알았지만 루트를 따로 정해주지 않았다
= 모든 노드를 생성한 후 부모가 없는 노드는 루트로 하여 탐색
*/
#include <bits/stdc++.h>
using namespace std;
struct tree {//트리 구조체
private:
    int lvmax[10001];//각 레벨의 최대값
    int lvmin[10001];//각 레벨의 최소값
    int N;// 노드 갯수
    int num;// idx 부여할 변수
    struct node {
        int idx;//traversal에 따라 매겨질 위치
        int left;//완쪽자식노드
        int right;//오른쪽 자식 노드
        int parents;// 부모 노드
    };
    node nodes[10001];
public:
    tree(int n) :N(n) {
        num = 0;
        for (int i = 1;i <= N;i++) nodes[i].parents = -1;//노드 부모 -1로 초기화(루트 찾기 위함)
        for (int i = 1;i <= N;i++) {// 최대 최소 초기화
            lvmax[i] = -1e9;
            lvmin[i] = 1e9;
        }
    }
    void makeNode(int current, int l, int r) {//노드 생성
        nodes[current].left = l;
        nodes[current].right = r;
        nodes[l].parents = nodes[r].parents = current;
    }
    void inorder(int current, int level = 1) {//중위 순회(inorder traversal)
        if (current == -1) return;
        inorder(nodes[current].left, level + 1);
        nodes[current].idx = ++num;//idx에 위치 부여
        if (nodes[current].idx > lvmax[level]) lvmax[level] = nodes[current].idx;//레벨마다 최대 최소 갱신
        if (nodes[current].idx < lvmin[level]) lvmin[level] = nodes[current].idx;
        inorder(nodes[current].right, level + 1);
    }
    void solve() {
        int root, ans = -1, t = 0;
        for (int i = 1;i <= N;i++) {//루트찾기
            if (nodes[i].parents == -1) {
                root = i;
                break;
            }
        }
        inorder(root);//inorder traversal
        for (int i = 1;i <= N;i++) {//레벨마다의 최대최소값을 통해 너비 계산
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