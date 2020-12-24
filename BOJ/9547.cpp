#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int  C[105], c, v, x;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &c, &v);
        priority_queue<p, vector<p>, greater<p>> V[101];
        priority_queue<p, vector<p>> pq;
        for (int i = 0;i < v;i++) {
            for (int j = 0;j < c;j++) {
                scanf("%d", &x);
                V[i].push({ j,x });
            }
            C[V[i].top().second]++;
        }
        for (int i = 1;i <= c;i++) pq.push({ C[i],i });
        int f = pq.top().second;
        pq.pop();
        int s = pq.top().second;
        if (C[f] > v / 2) printf("%d 1\n", f);
        else {
            int ff = 0, ss = 0;
            for (int i = 0;i < v;i++) {
                while (V[i].top().second != f && V[i].top().second != s) V[i].pop();
                if (f == V[i].top().second) ff++;
                else ss++;
            }
            printf("%d 2\n", ff > ss ? f : s);
        }
        memset(C, 0, sizeof(C));
    }
}