/*
Idea 1. 행 번호를 매기는 순서가 inorder traversal
= 중위 순회를 돌면 번호를 매길 수 있겠다.
Idea 2. inorder를 돌 때 level 마다 최대 최소값 관리
Idea 3. 루트가 정해져 있는줄 알았지만 루트를 따로 정해주지 않았다
= 모든 노드를 생성한 후 부모가 없는 노드는 루트로 하여 탐색
*/
#include <bits/stdc++.h>
using namespace std;
int lvmax[10001];//레벨 최대값
int lvmin[10001];//레벨 최소값
int parents[10001];//부모 노드
int l[10001];// 왼쪽 자식 노드
int r[10001];// 오른쪽 자식 노드
int idx[10001];// traversal에 따라 매겨질 노드의 행번호
int max_depth, num;// 최대 깊이와 번호 매길떄 사용할 num
void inorder(int current, int depth = 1) {//inorder traversal 
    if (current == -1) return;
    max_depth = max(max_depth, depth);//최대 높이 계산
    inorder(l[current], depth + 1);
    idx[current] = ++num;//idx에 번호 부여
    if (idx[current] > lvmax[depth]) lvmax[depth] = idx[current];//최대 최소 갱신
    if (idx[current] < lvmin[depth]) lvmin[depth] = idx[current];
    inorder(r[current], depth + 1);
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        int c;
        scanf("%d", &c);
        scanf("%d%d", &l[c], &r[c]);// 자식찾고 
        parents[l[c]] = parents[r[c]] = c;//부모 찾기
    }
    int root, ans = -1, t = 0;
    for (int i = 1;i <= N;i++) {
        if (!parents[i]) root = i;//부모가 없다면 루트
        lvmax[i] = -1e9;//최대 최소 초기화
        lvmin[i] = 1e9;
    }
    inorder(root);//inorder traversal
    for (int i = 1;i <= max_depth;i++) {//최대 깊이까지 너비 탐색
        if (ans < lvmax[i] - lvmin[i] + 1) {
            t = i;
            ans = lvmax[i] - lvmin[i] + 1;
        }
    }
    printf("%d %d", t, ans);
}