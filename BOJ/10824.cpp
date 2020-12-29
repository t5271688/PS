#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (int i = 1000000; i > 0; i /= 10) {
        if (b / i >= 1) {
            a *= i * 10;
            break;
        }
    }
    for (int i = 1000000; i > 0; i /= 10) {
        if (d / i >= 1) {
            c *= i * 10;
            break;
        }
    }
    printf("%lld", a + b + c + d);


}