/*
나누어 떨어지는 배열
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());
    for (int i : arr) if (!(i % divisor)) answer.emplace_back(i);
    if (answer.empty()) answer.emplace_back(-1);
    return answer;
}