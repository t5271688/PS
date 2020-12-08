#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool used[201];
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0;i < numbers.size();i++) {
        for (int j = 0;j < numbers.size();j++) {
            if (i != j && !used[numbers[i] + numbers[j]]) {
                answer.emplace_back(numbers[i] + numbers[j]);
                used[numbers[i] + numbers[j]] = true;
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}