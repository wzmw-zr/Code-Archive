/*************************************************************************
	> File Name: 1.LeetCode1711.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月07日 星期三 00时07分00秒
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

const long MOD = 1e9 + 7;

int countPairs(vector<int>& deliciousness) {
    vector<long> two_pows(22, 1);
    for (int i = 1; i <= 21; i++) two_pows[i] = two_pows[i - 1] * 2;
    unordered_map<int, long> mp;
    for (int x : deliciousness) mp[x]++;
    long ans = 0;
    for (auto &&[val, cnt] : mp) {
        for (int x : two_pows) {
            if (2 * val < x) break;
            if (!mp.count(x - val)) continue;
            if (2 * val == x) 
                ans = (ans + (mp[val] * (mp[val] - 1) / 2) % MOD) % MOD;
            else 
                ans = (ans + mp[val] * mp[x - val] % MOD) % MOD;
        }
    }
    return ans;
}

int main() {
    return 0;
}
