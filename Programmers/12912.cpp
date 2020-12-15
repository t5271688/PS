/*
두 정수 사이의 합
*/
#include <bits/stdc++.h>
using namespace std;
long long solution(int a, int b) {
    int n = abs(a - b);
    vector<int> v(n + 1);
    iota(v.begin(), v.end(), min(a, b));
    return accumulate(v.begin(), v.end(), 0LL);
}