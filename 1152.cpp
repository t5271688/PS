#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    getline(cin,S);
    int ans = 0, i = -1;
    bool flag = true;
    while (S[++i] != '\0')
    {
        if(S[i]==' ')
            flag=true;
        else if(flag){
            ans++;
            flag=false;
        }
    }
    cout<<ans;
    return 0;
}