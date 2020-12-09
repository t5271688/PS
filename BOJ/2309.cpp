#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> V(9);
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &V[i]);
        sum += V[i];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - V[i] - V[j] == 100) {
                V[j] = 0;
                V[i] = 0;
                sort(V.begin(), V.end());
                for (int k = 2; k < 9; k++) printf("%d\n", V[k]);
                return 0;
            }
        }
    }
}