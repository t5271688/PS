#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> v;
    int answer = 0, pos = 1;
    while (n) {
        v.push_back(n % 3);
        n /= 3;
    }
    for (auto iter = v.rbegin();iter != v.rend();++iter, pos *= 3) answer += pos * *iter;
    return answer;
}