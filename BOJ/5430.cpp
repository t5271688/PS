#include <bits/stdc++.h>
using namespace std;
char P[100010];
char X[400010];
int main() {
    //freopen("input.txt", "r", stdin);
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%d%s", P, &N, X);
        deque<int> DQ;
        int len1 = strlen(X);
        int len2 = strlen(P);
        int tmp = 0;
        bool error = false, Rear = false;
        for (int i = 1; i < len1 - 1; i++) {
            if (X[i] == ',') {
                DQ.push_back(tmp);
                tmp = 0;
            }
            else tmp = (tmp * 10) + (X[i] - '0');
        }
        if (tmp) DQ.push_back(tmp);
        for (int i = 0; i < len2; i++) {
            if (P[i] == 'R') Rear = !Rear;
            else if (P[i] == 'D') {
                if (DQ.empty()) {
                    error = true;
                    break;
                }
                else {
                    if (Rear) DQ.pop_back();
                    else DQ.pop_front();
                }
            }
        }
        if (error) printf("error\n");
        else {
            printf("[");
            while (!DQ.empty()) {
                if (Rear) {
                    printf("%d", DQ.back());
                    DQ.pop_back();
                }
                else {
                    printf("%d", DQ.front());
                    DQ.pop_front();
                }
                if (!DQ.empty()) printf(",");
            }
            printf("]\n");
        }
    }
}
