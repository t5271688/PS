#include <bits/stdc++.h>
using namespace std;
int N, t;
int _max = -2e9, _min = 2e9;
vector<int> nums;
vector<int> ops;
vector<int> used;
void back_tracking(int idx = 0) {
    if (idx == N - 1) {
        int sum = nums[0];
        for (int i = 1; i < N; i++) {
            if (used[i - 1] == 0) sum += nums[i];
            if (used[i - 1] == 1) sum -= nums[i];
            if (used[i - 1] == 2) sum *= nums[i];
            if (used[i - 1] == 3) sum /= nums[i];
        }
        _max = max(_max, sum);
        _min = min(_min, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (ops[i]) {
            ops[i]--;
            used.emplace_back(i);
            back_tracking(idx + 1);
            used.pop_back();
            ops[i]++;
        }
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &t);
        nums.emplace_back(t);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &t);
        ops.emplace_back(t);
    }
    back_tracking();
    printf("%d\n", _max);
    printf("%d", _min);
}