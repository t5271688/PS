#include <cstdio>
#include <vector>
using namespace std;
vector<int> gear[4];
int K;
void rotate(int idx, int d, int from = 0) {
    if (from == 0) {
        if (idx - 1 >= 0 && gear[idx - 1][2] != gear[idx][6]) rotate(idx - 1, -d, -1);
        if (idx + 1 <= 3 && gear[idx][2] != gear[idx + 1][6]) rotate(idx + 1, -d, 1);
    }
    if (from == -1) if (idx - 1 >= 0 && gear[idx - 1][2] != gear[idx][6]) rotate(idx - 1, -d, -1);
    if (from == 1) if (idx + 1 <= 3 && gear[idx][2] != gear[idx + 1][6]) rotate(idx + 1, -d, 1);
    if (d > 0) {
        gear[idx].insert(gear[idx].begin(), *(gear[idx].end() - 1));
        gear[idx].erase(gear[idx].end() - 1);
    }
    else {
        gear[idx].push_back(*gear[idx].begin());
        gear[idx].erase(gear[idx].begin());
    }
}
int main() {
    for (int i = 0; i < 4; i++) {
        gear[i].resize(8);
        for (int j = 0; j < 8; j++) scanf("%1d", &gear[i][j]);
    }
    scanf("%d", &K);
    while (K--) {
        int T, dir;
        scanf("%d %d", &T, &dir);
        rotate(T - 1, dir);
    }
    printf("%d\n", gear[0][0] * 1 + gear[1][0] * 2 + gear[2][0] * 4 + gear[3][0] * 8);
}
