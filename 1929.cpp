#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
bool F[MAX] = {
    1,
    1,
    0,
};
int main()
{
    int N, M;
    cin >> M >> N;
    for (int i = 2; i < MAX; i++)
    {
        if (!F[i])
            for (int j = 2; j * i < MAX; j++)
                F[j * i] = true;
    }
    for (int i = M; i <= N; i++)
        if (!F[i])
            cout << i << "\n";
}