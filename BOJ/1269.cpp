#include <bits/stdc++.h>
using namespace std;
unordered_map<int, bool> A;
int N, M, val;
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0;i < N;i++) {
        scanf("%d", &val);
        A.insert({ val,true });
    }
    for (int i = 0;i < M;i++) {
        scanf("%d", &val);
        if (A.find(val) != A.end()) A.erase(val);
        else A.insert({ val,true });
    }
    printf("%d", A.size());
}