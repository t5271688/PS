#include <bits/stdc++.h>
using namespace std;
int w, h;//���� ���� w, ���� ���� h
int A[51][51];//���� �迭
int dir[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1} };
//�̵��� �����ϰ� ǥ���ϱ� ���� ���� �迭 dir, ���� �� �� �� �� �ϼ� ���� �ϵ� ����
bool visited[51][51];//�湮 üũ�迭 visited
bool isInside(int y, int x) {//���� �迭�� ������� üũ�� �Լ� isInside(y,x)
    return y > 0 && y <= h && x > 0 && x <= w;
}
int dfs(int y, int x) {//dfs(y,x)
    visited[y][x] = true;//�湮 üũ
    for (int i = 0;i < 8;i++) {//8���⿡ ����
        int ny = y + dir[i][0], nx = x + dir[i][1];//8������ ���ο� ��ǥ�� ����
        if (!isInside(ny, nx) || visited[ny][nx]) continue;//���� ���̰ų� �湮���� ������ skip
        if (A[ny][nx]) dfs(ny, nx);//�ɾ �� �ִ� ���̶�� dfs(ny,nx)
    }
    return 1;
}
int main() {
    while (true) {
        memset(visited, 0, sizeof(visited));//�� �׽�Ʈ���̽��� visited�迭 �ʱ�ȭ
        int ans = 0;//������ ���� ���� ans
        scanf("%d%d", &w, &h);//w,h �Է�
        if (!w && !h) return 0;//���� 0,0 �̸� ����
        for (int i = 1;i <= h;i++) for (int j = 1;j <= w;j++) scanf("%d", &A[i][j]);
        //���� �Է�
        for (int i = 1;i <= h;i++)
            for (int j = 1;j <= w;j++)
                if (!visited[i][j] && A[i][j]) ans += dfs(i, j);
        //A[i][j]�� �湮���� ���� ���̸� dfs(i,j);
        printf("%d\n", ans);
    }
}