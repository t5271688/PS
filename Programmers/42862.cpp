#include <bits/stdc++.h>
int arr[31];
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    fill(arr, arr + 31, 1);
    int answer = 0;
    for (int i : lost) arr[i]--;
    for (int i : reserve) arr[i]++;
    for (int i = 1;i <= n;i++) {
        if (arr[i] == 2 && !arr[i - 1]) {
            arr[i - 1]++;
            arr[i]--;
        }
        if (arr[i] == 2 && !arr[i + 1]) {
            arr[i + 1]++;
            arr[i]--;
        }
    }
    for (int i = 1;i <= n;i++) answer += !(!arr[i]);
    return answer;
}