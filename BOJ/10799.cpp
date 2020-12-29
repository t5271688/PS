#include <cstdio>
#include <stack>
using namespace std;
char S[100001];
int main() {
    stack<char> st;
    scanf("%s", S);
    int ans = 0;
    for (int i = 0; S[i]; i++) {
        if (S[i] == '(') st.push(S[i]);
        else {
            st.pop();
            if (S[i - 1] == '(') ans += st.size();
            else ans++;
        }
    }
    printf("%d\n", ans);
}