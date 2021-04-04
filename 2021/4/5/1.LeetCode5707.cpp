/*************************************************************************
	> File Name: 1.LeetCode5707.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月05日 星期一 00时04分50秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;


long encode(vector<long> &freq) {
    long code = 0;
    long one = 1;
    for (long i = 1; i < freq.size(); i++) code += freq[i] * (one << (8 * i - 8));
    return code;
}

long dfs(unordered_map<long, long> &mp, vector<long> &freq, long nums, long sum, int &batchSize) {
    if (nums == 0) return 0;
    long code = encode(freq);
    if (mp.count(code)) return mp[code];
    long ans = 0;
    for (long i = 1; i < freq.size(); i++) {
        if (freq[i] == 0) continue;
        freq[i] -= 1;
        long temp = dfs(mp, freq, nums - 1, sum + i, batchSize);
        ans = max(ans, temp);
        freq[i] += 1;
    }
    ans += (sum % batchSize == 0 ? 1 : 0);
    mp[code] = ans;
    return ans;
}

int maxHappyGroups(int batchSize, vector<int>& groups) {
    for (int &x : groups) x %= batchSize;
    vector<long> freq(9, 0);
    long nums = 0;
    for (long x : groups) freq[x]++, nums += (x == 0 ? 0 : 1);
    unordered_map<long, long> mp;
    mp[0] = 0;
    dfs(mp, freq, nums, 0, batchSize);
    long ans = 0;
    for (auto &&[x, cnt] : mp) ans = max(ans, cnt);
    ans += freq[0];
    return ans;
}

int main() {
    return 0;
}
