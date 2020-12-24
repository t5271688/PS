#include <bits/stdc++.h>
using namespace std;
struct student {
    string name;
    int kor, eng, mat;
    bool operator <(const student& A) {
        if (kor == A.kor && mat == A.mat && eng == A.eng) return name < A.name;
        if (kor == A.kor && eng == A.eng) return mat > A.mat;
        if (kor == A.kor) return eng < A.eng;
        else return kor > A.kor;
    }
};
vector<student> V;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0;i < N;i++) {
        string name;
        int eng, kor, mat;
        cin >> name >> kor >> eng >> mat;
        V.push_back({ name,kor,eng,mat });
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < N; i++) cout << V[i].name << '\n';

}