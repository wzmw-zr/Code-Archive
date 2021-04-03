/*************************************************************************
	> File Name: 3.LeetCode5708.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月03日 星期六 23时00分00秒
 ************************************************************************/

#include<iostream>
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

int rev(int x) {
    int num = 0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return num;
}

int countNicePairs(vector<int>& nums) {
    unordered_map<int, long> mp;
    for (int &x : nums) mp[x - rev(x)]++;
    const long mod = 1e9 + 7;
    long ans = 0;
    for (auto &&[x, cnt] : mp) ans = (ans + cnt * (cnt - 1) / 2) % mod;
    return ans;
}

int main() {
    return 0;
}
