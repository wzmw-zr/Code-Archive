/*************************************************************************
	> File Name: 1.LeetCode47.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月18日 星期五 08时03分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

void dfs(set<vector<int>> &st, vector<int> &nums, vector<int> &check, vector<int> &permutaion, int ind) {
    if (ind == nums.size()) {
        st.insert(permutaion);
        return ;
    }
    cout << ind << endl;
    for (int i = 0; i < nums.size(); i++) {
        if (check[i]) continue;
        check[i] = 1;
        permutaion[i] = nums[ind];
        dfs(st, nums, check, permutaion, ind + 1);
        check[i] = 0;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    set<vector<int>> st;
    vector<int> check(nums.size() + 5, 0);
    vector<int> permutaion(nums.size(), 0);
    dfs(st, nums, check, permutaion, 0);
    vector<vector<int>> ans;
    for (auto &x : st) ans.push_back(x);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    auto ans = permuteUnique(nums);
    for (auto &x : ans) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}
