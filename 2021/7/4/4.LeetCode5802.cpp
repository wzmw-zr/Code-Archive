/*************************************************************************
	> File Name: 4.LeetCode5802.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月04日 星期日 11时07分14秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long quick_pow(long long b, long long m) {
    long long ans = 1;
    while (m) {
        if (m & 1) ans = (ans * b) % MOD;
        m >>= 1;
        b = (b * b) % MOD;
    }
    return ans;
}

int countGoodNumbers(long long n) {
    long long res = quick_pow(5, (n + 1) / 2) * quick_pow(4, n / 2);
    res %= MOD;
    return res;
}

int main() {
    return 0;
}
