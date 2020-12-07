/*
A����� B�ŵ������� ���ϴ� ����
Idea 1. ���� ������ �̿��� �ŵ����� ���
��� ������ Ư���� ������� �����ϸ� O(N^3)�� �䱸�ȴ�
N ũ�� ������ 5�̱� ������ �ִ� 1���� 125���� ������ �䱸�ǰ�, B�� range�� 10���̱� ������
naive�ϰ� ���ϸ� �ð��ʰ��� ����.
�׷��� �ŵ������� ���� ���������� �ɰ��� �ִ� ����Ƚ���� O(logB)�� �ǹǷ� �ð��ȿ� ��� �� �� �ִ�.
Idea 2. ������ �����ε�
������ �����ε��� ���� matrix�� ������ �ڿ������� �������.

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;// 2^64 ���� long long
typedef vector<vector<ll>> matrix;// ����� ��Ÿ���� matrix 
const ll mod = 1000;// ����
matrix operator*(const matrix& a, const matrix& b) {//����� ���� ����
    int n = a.size();
    matrix ret(n, vector<ll>(n));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            for (int k = 0;k < n;k++) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
        }
    }
    return ret;
}
matrix identity(int n) {// ���� ���(�� ������ ��� ��������� �ʿ��� ���� ���Ǳ����� �������� �ʴ´�.)
    matrix id(n, vector<ll>(n));
    for (int i = 0;i < n;i++) id[i][i] = 1;
    return id;
}
matrix matpow(const matrix& a, ll b) {//����� �ŵ������� ���� ���������� ����
    if (!b) return identity(a.size());// 0�����ϰ�� ���� ���
    else if (b == 1) return a;//b�� 1�� ��� a��� ����ü
    if (b % 2 == 0) {// b�� 2�� �����������,
        matrix ret = matpow(a, b / 2);// b/2 ���� ��ŭ�� ����� ���� ���� ����
        return ret * ret;// b/2�������� ���ؼ� b���� ����
    }
    else return matpow(a, b - 1) * a;//������ �������� ������� 1��ŭ���� a�� ���� �����־� ¦���� �����
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