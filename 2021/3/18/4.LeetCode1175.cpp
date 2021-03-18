/*************************************************************************
	> File Name: 4.LeetCode1175.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月18日 星期四 22时14分35秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;

long full_permute_cnt(int cnt) {
    long ans = 1;
    for (long i = 1; i <= cnt; i++) ans = (ans * i) % MOD;
    return ans;
}

int numPrimeArrangements(int n) {
    vector<int> prime(n + 1, 1);
    prime[0] = 0;
    prime[1] = 0;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) continue;
        cnt++;
        for (int j = 2; j * i <= n; j++) prime[j * i] = 0;
    }
    long ans = (full_permute_cnt(cnt) * full_permute_cnt(n - cnt)) % MOD;
    return (int) ans;
}

int main() {
    return 0;
}
