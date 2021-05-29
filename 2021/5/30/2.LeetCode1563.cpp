/*************************************************************************
	> File Name: 2.LeetCode1563.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月30日 星期日 00时13分38秒
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


int dfs(vector<int> &pre, int l, int r, vector<vector<int>> &mp) {
    if (l == r) return 0;
    if (mp[l][r]) return mp[l][r];
    int ans = 0;
    for (int i = l; i < r; i++) {
        int left = pre[i] - pre[l - 1];
        int right = pre[r] - pre[i];
        if (left < right) {
            ans = max(ans, left + dfs(pre, l, i, mp));
        } else if (left > right) {
            ans = max(ans, right + dfs(pre, i + 1, r, mp));
        } else {
            ans = max(ans, left + max(dfs(pre, l, i, mp), dfs(pre, i + 1, r, mp)));
        }
    }
    return mp[l][r] = ans;
}

int stoneGameV(vector<int>& stoneValue) {
    int l = 1, r = stoneValue.size();
    vector<int> pre(r + 1, 0);
    vector<vector<int>> mp(r + 1, vector<int>(r + 1, 0));
    for (int i = 0; i < r; i++) 
        pre[i + 1] = pre[i] + stoneValue[i];
    return dfs(pre, l, r, mp);
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << stoneGameV(nums) << endl;
    return 0;
}
