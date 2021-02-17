#include <bits/stdc++.h>
const int MAX_V = 1005;
using namespace std;
int main() {
    int T;
    for (scanf("%d", &T); T--;) {
        int cost[1005] = { 0 };// 각 건물 건설에 필요한 시간
        long long tcost[1005] = { 0 };//각 건물을 짓는데 필요한 최소 시간 
        int D[1005] = { 0 };//정점의 Indegree
        vector<int> adj[MAX_V];//그래프
        int N, K, W;
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; i++) scanf("%d", cost + i);
        for (int i = 1; i <= K; i++) {//간선 정보 입력 받으며 Indegree 증가
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            D[b]++;//indegree ++
        }
        scanf("%d", &W);
        queue<int> Q;
        for (int i = 1; i <= N; i++)
            if (D[i] == 0) {// Indegree가 0인 정점은 tcost=cost이다.
                tcost[i] = cost[i];
                Q.push(i);// Indegree가 0인 정점 큐에 삽입
            }
        for (int i = 1; i <= N; i++) {//정점을 모두 훑으며 위상정렬
            int curr = Q.front();//큐에는 Indegree가 0인 정점이 들어있다.
            Q.pop();
            for (int next : adj[curr]) {//현 정점에서 뻗어나가는 간선의 tcost를 조정하고
                tcost[next] = max(tcost[next], tcost[curr] + cost[next]);
                if (--D[next] == 0) Q.push(next);// Indegree를 감소시키며 0이면 큐에 삽입
            }
        }
        printf("%lld\n", tcost[W]);
    }
    return 0;
}