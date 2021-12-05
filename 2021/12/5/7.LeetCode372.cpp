/*************************************************************************
	> File Name: 7.LeetCode372.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月05日 星期日 15时04分26秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int MOD = 1337;

int qpow(int x, int y) {
    int base = x, ans = 1;
    while (y) {
        if (y & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        y >>= 1;
    }
    return ans;
}

int dfs(int a, vector<int> &b, int ind) {
    if (ind == -1) return 1;
    return qpow(dfs(a, b, ind - 1), 10) * qpow(a, b[ind]) % MOD;
}

int superPow(int a, vector<int>& b) {
    int n = b.size();
    a %= MOD;
    return dfs(a, b, n - 1);
}

int main() {
    return 0;
}
