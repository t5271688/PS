/*
������ �а� �� �����غ���, ������ ���� ���� ������ ������ ���,
���� ���� �������� ������ �����°� �����̴�.
�� ������ ť�� �����Ͽ� ���� ���� ������ ���� ����ִ¸�ŭ ���,
���� ���� �������� ������ ������ ¥�� �ȴ�.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<int> q;

int main() {
    int n, s;
    ll w, c = 0;//���� ������ ���� ���� ��û���� ū ���� �� �� �ֱ⶧���� long long
    scanf("%d%lld", &n, &w);
    for (int i = 0;i < n;i++) {
        scanf("%d", &s);
        q.push(s);//��¥������ ť�� �־��ش�
    }
    while (1) {
        int now = q.front();//ť���� ������ ����
        q.pop();
        if (q.empty()) {//������ ���������̸� ����ִ°� �� �Ǵ�.
            w += c * now;
            break;
        }
        if (now > q.front()) {//���� ���� �������� ������ �� �Ǵ�.
            w += c * now;
            c = 0;
        }
        else if (now < q.front()) {//���� ���� ������ ����ִ¸�ŭ �� ���.
            c += w / now;
            w %= now;
        }
    }
    printf("%lld", w);
}