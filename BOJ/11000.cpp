/*
Idea 1. 모든 강의를 소화할 수 있는 최소의 강의실 갯수 찾기
강의실 갯수가 추가되는 기준 : 추가하려는 강의 기준으로 모든 강의실이 unavailalbe할 때
이 기준을 지키면서 강의실을 추가해보기
Idea 2. 현재 강의실 중 available한 강의실이 있는지 찾기
강의실이 available한 기준 : 현시점 시작하는 강의의 시작 시간보다 마지막 강의의 종료시간이 더 빠를 때
모든 강의실을 일일히 탐색한다면 최악 O(n) 소요
= 우선순위 큐를 이용해 종료시간만을 관리하기
우선순위 큐를 min heap으로 사용하여 사용된 강의실 중 종료시간이 가장 빠른 강의실과 현재 강의 비교
모든 강의실이 unavailable하다면(min heap의 top보다 현재 강의의 시작 시간이 빠르다면) 강의실을 추가함
어떤 강의실이 available하다면(min heap의 top이 강의 시작보다 빠르다면) top을 pop하고 강의실을 추가(그 강의실을 사용하는 개념)
정렬=O(NlogN)
1회 비교에 heap의 삽입 삭제가 최대 1회씩 = O(logN), 이 비교를 N회
시간복잡도 O(NlogN)에 처리 가능
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pi;// 강의 정보를 담을 pair<int,int> 구조체 Pi
vector<Pi> V;//Pi의 벡터 V
int N, s, t;
priority_queue<int, vector<int>, greater<int>> PQ;// min heap 우선순위 큐
int main() {
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {//강의정보 벡터에 담고
        scanf("%d%d", &s, &t);
        V.push_back({ s,t });
    }
    sort(V.begin(), V.end());// 시작 시간순으로 정렬
    PQ.push(V[0].second);//최초 1개 강의실은 무조건 사용해야함, 1번째 종료시간 PQ에 삽입
    for (int i = 1;i < N;i++) {
        if (PQ.top() <= V[i].first) {// available한 강의실이 있다면(PQ의 top이 현 강의 시작보다 빠르다면)
            PQ.pop();// PQ pop하고 현 강의 종료 시간 삽입(그 강의실을 사용하는 개념)
            PQ.push(V[i].second);
        }
        else PQ.push(V[i].second);//아니면 강의실 추가
    }
    printf("%d", PQ.size());//PQ에 남아있는 종료 시간의 개수(PQ의 크기)가 강의실의 사용갯수(PQ의 크기가 줄어드는 연산이 없기 때문에)
}