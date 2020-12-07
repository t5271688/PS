/*
A행렬의 B거듭제곱을 구하는 문제
Idea 1. 분할 정복을 이용한 거듭제곱 계산
행렬 연산을 특별한 기법없이 구현하면 O(N^3)이 요구된다
N 크기 제한이 5이기 때문에 최대 1곱당 125번의 연산이 요구되고, B의 range가 10억이기 때문에
naive하게 곱하면 시간초과가 난다.
그러나 거듭제곱을 분할 정복법으로 쪼개면 최대 연산횟수는 O(logB)가 되므로 시간안에 들어 갈 수 있다.
Idea 2. 연산자 오버로딩
연산자 오버로딩을 통해 matrix의 연산을 자연스럽게 만들었다.

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;// 2^64 정수 long long
typedef vector<vector<ll>> matrix;// 행렬을 나타내는 matrix 
const ll mod = 1000;// 모듈라
matrix operator*(const matrix& a, const matrix& b) {//행렬의 곱셈 구현
    int n = a.size();
    matrix ret(n, vector<ll>(n));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            for (int k = 0;k < n;k++) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
        }
    }
    return ret;
}
matrix identity(int n) {// 단위 행렬(이 문제는 사실 단위행렬이 필요한 기저 조건까지는 진입하지 않는다.)
    matrix id(n, vector<ll>(n));
    for (int i = 0;i < n;i++) id[i][i] = 1;
    return id;
}
matrix matpow(const matrix& a, ll b) {//행렬의 거듭제곱을 분할 정복법으로 구현
    if (!b) return identity(a.size());// 0제곱일경우 단위 행렬
    else if (b == 1) return a;//b가 1일 경우 a행렬 그자체
    if (b % 2 == 0) {// b가 2로 나누어떨어지면,
        matrix ret = matpow(a, b / 2);// b/2 제곱 만큼의 행렬을 구해 놓고 곱셈
        return ret * ret;// b/2제곱끼리 곱해서 b제곱 리턴
    }
    else return matpow(a, b - 1) * a;//나누어 떨어지지 않을경우 1만큼빼고 a를 따로 곱해주어 짝수로 만들기
}
ll N, B;
int main() {
    cin >> N >> B;
    matrix A(N, vector<ll>(N));
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> A[i][j];
            A[i][j] %= mod;
        }
    }
    A = matpow(A, B);
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) cout << A[i][j] << " ";
        cout << "\n";
    }
    return 0;
}