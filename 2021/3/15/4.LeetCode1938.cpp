/*************************************************************************
	> File Name: 4.LeetCode1938.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月15日 星期一 11时06分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &st, int ind, int &n, int cnt, int len) {
    if (cnt == len) {
        ans.push_back(st);
        return ;
    }
    if (ind == n) return ;
    st.push_back(nums[ind]);
    dfs(nums, ans, st, ind + 1, n, cnt + 1, len);
    st.pop_back();
    dfs(nums, ans, st, ind + 1, n, cnt, len);
}

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> st;
    for (int i = 0; i <= n; i++) dfs(nums, ans, st, 0, n, 0, i);
    return ans;
}

int main() {
    return 0;
}
