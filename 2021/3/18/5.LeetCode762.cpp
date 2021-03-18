/*************************************************************************
	> File Name: 5.LeetCode762.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月18日 星期四 22时30分03秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> prime(33, 1);

void init() {
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= 32; i++) {
        if (!prime[i]) continue;
        for (int j = 2; i * j <= 32; j++) prime[i * j] = 0;
    }
}

int countPrimeSetBits(int L, int R) {
    init();
    int ans = 0;
    for (int i = L; i <= R; i++) ans += prime[__builtin_popcount(i)];
    return ans;
}

int main() {
    return 0;
}
