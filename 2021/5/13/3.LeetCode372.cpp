/*************************************************************************
	> File Name: 3.LeetCode372.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月13日 星期四 22时12分15秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int MOD = 1337;

int fastpow(int base, int num) {
    int ans = 1;
    while (num) {
        if (num & 1) ans = ans * base % MOD;
        base = base * base % MOD;
        num >>= 1;
    }
    return ans;
}

int superPow(int a, vector<int>& b) {
    a %= 1337;
    int ans = 1;
    int n = b.size();
    int base = a;
    for (int i = n - 1; i >= 0; i--) {
        ans = ans * fastpow(base, b[i]) % MOD;
        base = fastpow(base, 10);
    }
    return ans;
}


int main() {
    return 0;
}
