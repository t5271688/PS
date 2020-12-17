/*
문제를 읽고 잘 생각해보면, 다음날 코인 값이 오르면 무조건 사고,
코인 값이 떨어지면 무조건 던지는게 최적이다.
이 구조를 큐로 관리하여 내일 값이 오르면 지금 살수있는만큼 사고,
내일 값이 떨어지면 무조건 던지게 짜면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<int> q;

int main() {
    int n, s;
    ll w, c = 0;//코인 갯수와 가진 돈은 엄청나게 큰 값이 될 수 있기때문에 long long
    scanf("%d%lld", &n, &w);
    for (int i = 0;i < n;i++) {
        scanf("%d", &s);
        q.push(s);//날짜순으로 큐에 넣어준다
    }
    while (1) {
        int now = q.front();//큐에서 오늘을 뺀다
        q.pop();
        if (q.empty()) {//오늘이 마지막날이면 들고있는걸 다 판다.
            w += c * now;
            break;
        }
        if (now > q.front()) {//내일 값이 떨어지면 가진걸 다 판다.
            w += c * now;
            c = 0;
        }
        else if (now < q.front()) {//내일 값이 오르면 살수있는만큼 다 산다.
            c += w / now;
            w %= now;
        }
    }
    printf("%lld", w);
}