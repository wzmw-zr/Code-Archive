/*************************************************************************
	> File Name: 1.LeetCode29.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月12日 星期二 09时09分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

// WA
int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (dividend == INT32_MIN && divisor == -1) return INT32_MAX;
    if (divisor == INT32_MIN) {
        if (dividend == INT32_MIN) return 1;
        return 0;
    }
    int flag = (((dividend > 0) & (divisor > 0)) | ((dividend < 0) & (divisor < 0))) ? 1 : -1;
    unsigned int x = abs(dividend);
    unsigned int y = abs(divisor);
    int ans = 0;
    while (y <= x) {
        unsigned int t = 0;
        while ((y << t) <= x) t++;
        x -= (y << (t - 1));
        ans += (1 << (t - 1));
    }
    ans *= flag;
    return ans;
}

int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor) << endl;
    return 0;
}
