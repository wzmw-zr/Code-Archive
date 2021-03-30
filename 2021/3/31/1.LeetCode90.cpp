/*************************************************************************
	> File Name: 1.LeetCode90.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月31日 星期三 00时02分11秒
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

void dfs(vector<int> &nums, int ind, int &n, vector<int> &subset, set<vector<int>> &st) {
    st.insert(subset);
    if (ind == n) return ;
    subset.push_back(nums[ind]);
    dfs(nums, ind + 1, n, subset, st);
    subset.pop_back();
    dfs(nums, ind + 1, n, subset, st);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    vector<int> subset;
    int n = nums.size();
    dfs(nums, 0, n, subset, st);
    vector<vector<int>> ans;
    for (auto x : st) ans.push_back(x);
    return ans;
}

int main() {
    return 0;
}
