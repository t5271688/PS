/*
Idea 1. Bidirectional Graph에서 Cycle 찾기
방향 그래프에서 사이클을 찾을 때, 방문한 정점을 다시 방문하면 사이클이 있음
그러나 양방향이기 때문에 일반적인 방법으로 하면 간선마다 사이클이 생김
= 크기가 3이상인 사이클만 찾도록 조건문을 만들자

Idea 2. 사이클에 불필요한 간선이 포함되지 않도록 경로 관리 하기
DFS를 진행할 때 각 정점에서 어느 경로로 이동하는지 기록(to 배열)
이미 방문한 정점(사이클의 시작)을 방문했을 때,to 배열을 추적하며 사이클 탐색

사이클을 찾은 후, 사이클 전체에서 사이클이 아닌 정점으로의 거리를 BFS로 탐색
DFS O(N) BFS O(N)
시간복잡도 O(N)에 해결 가능
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 3001;
typedef vector<int> vi;
vi adj[MAX];// 그래프를 표현할 인접 리스트
queue<int> Q;// BFS에 사용할 queue
int visited[MAX], dist[MAX], to[MAX], N, u, v;//방문배열 visited, 거리배열 dist, 사이클 추적용 배열 to
bool DFS(int curr, int D) {//DFS 
    int ret;
    if (visited[curr]) {//이미 방문한 정점인 경우이며,
        if (D - dist[curr] >= 3) {//사이클의 크기가 3이상(사이클의 시작위치와 현재위치의 거리차가 3이상)이면,
            for (int temp = to[curr];temp != curr;temp = to[temp]) visited[temp] = 2;//사이클 생성 반복문(to 배열을 추적하며 사이클 생성)
            visited[curr] = 2;//사이클에 포함된 정점들은 2로 체크
            return true;//true 리턴
        }
        else return false;// 방문한 정점이지만 사이클의 크기가 2미만(인접한 정점)일 때는 false 리턴
    }
    visited[curr] = 1;//방문 체크
    dist[curr] = D;// 거리 표시
    for (int next : adj[curr]) {//DFS 반복
        to[curr] = next;// 현 정점에서 어느 정점으로 가는지 기록
        if (ret = DFS(next, D + 1)) return ret;//DFS에서 true 리턴하면(사이클을 감지하고 생성했다면) 그대로 true 리턴
    }
    return ret;//이 탐색에서 사이클을 찾지 못했으면 false 리턴
}
void BFS() {//BFS
    while (!Q.empty()) {//사이클에 포함된 정점으로부터 다른 정점까지의 거리 계산
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
    for (int i = 0;i < N;i++) {//인접 리스트 구성하기
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);//DFS 시작
    for (int i = 1;i <= N;i++) {//DFS완료 후, 사이클에 포함된 정점을 모두 큐에 넣고 거리를 0으로 설정
        if (visited[i] == 2) {
            Q.push(i);
            dist[i] = 0;
        }
        else visited[i] = 0;//비 사이클 정점이라면 방문 배열 초기화
    }
    BFS();//BFS
    for (int i = 1;i <= N;i++) printf("%d ", dist[i]);
    return 0;
}