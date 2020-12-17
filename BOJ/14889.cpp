/*
백트래킹 재귀함수로 전수조사 하였다.
*/
#include <bits/stdc++.h>
using namespace std;
int S[21][21], N, isteam[21];//팀시너지를 관리하는S배열, i번째인원이 어느팀인지 관리와 1,-1팀배정으로 연산을 쉽게할 isteam 배열
int back_tracking(int idx = 1) {
    int ret = 1e9;
    if (idx == N + 1) {//모든 인원을 배치 하였을 때,
        if (accumulate(isteam + 1, isteam + N + 1, 0)) return ret;//isteam의 총 합이 0이 아니라면 N/2명씩 들어간게 아니므로 불가능
        ret = 0;
        for (int i = 1;i <= N;i++) for (int j = 1;j <= N;j++) if (isteam[i] == isteam[j]) ret += S[i][j] * isteam[i];// i와j가 같은 팀일 경우, S[i][j]에 isteam을 곱해 차를 관리
        return abs(ret);//절대값 리턴
    }
    isteam[idx] = 1;//idx가 스타트 팀일때
    ret = min(ret, back_tracking(idx + 1));//백트래킹
    isteam[idx] = -1;//idx가 링크 팀일때
    ret = min(ret, back_tracking(idx + 1));//백트래킹
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 1;i <= N;i++) for (int j = 1;j <= N;j++) scanf("%d", &S[i][j]);
    printf("%d", back_tracking());//함수 시작
}