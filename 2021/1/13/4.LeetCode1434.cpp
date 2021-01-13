/*************************************************************************
	> File Name: 4.LeetCode1434.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月13日 星期三 09时20分34秒
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

int dfs(vector<vector<int>> &hats, vector<bool> &hats_use, int ind, int &n) {
    if (ind == n) return 0;
    int ans = 0;
    for (int &x : hats[ind]) {
        if (hats_use[x]) continue;
        hats_use[x] = true;
        ans += dfs(hats, hats_use, ind + 1, n);
        ans %= 1000000007;
        hats_use[x] = false;
    }
    return ans;
}

int numberWays(vector<vector<int>>& hats) {
    int n = hats.size();
    vector<bool> hats_use(50, false);
    return dfs(hats, hats_use, 0, n);
}

int main() {
    return 0;
}
