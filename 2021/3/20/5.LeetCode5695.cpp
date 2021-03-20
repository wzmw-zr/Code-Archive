/*************************************************************************
	> File Name: 5.LeetCode5695.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月20日 星期六 22时53分57秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;


// TLE

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void dfs(unordered_map<int, int> &mp, int ind, int &n, int score, int &ans) {
    if (ind > n) {
        ans = max(score, ans);
        return ;
    }
    for (auto &&[num1, cnt1] : mp) {
        if (cnt1 == 0) continue;
        mp[num1]--;
        for (auto &&[num2, cnt2] : mp) {
            if (cnt2 == 0) continue;
            mp[num2]--;
            dfs(mp, ind + 1, n, score + ind * gcd(num1, num2), ans);
            mp[num2]++;
        }
        mp[num1]++;
    }
}

int maxScore(vector<int>& nums) {
    int n = nums.size() / 2;
    unordered_map<int, int> mp;
    for (int &x : nums) mp[x]++;
    int ans = 0;
    dfs(mp, 1, n, 0, ans);
    return ans;
}

int main() {
    return 0;
}
