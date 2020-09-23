/*************************************************************************
	> File Name: 1.LeetCode501.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月24日 星期四 07时17分02秒
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode *root, map<int, int> &mp) {
    if (!root) return ;
    mp[root->val]++;
    dfs(root->left, mp);
    dfs(root->right, mp);
}

vector<int> findMode(TreeNode* root) {
    map<int, int> mp;
    vector<pair<int, int>> nums;
    vector<int> ans;
    dfs(root, mp);
    for (auto &x : mp) nums.push_back(x);
    sort(nums.begin(), nums.end(), [](pair<int, int> a, pair<int, int> b){ return a.second > b.second; });
    int num = nums[0].second;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i].second == num) ans.push_back(nums[i].first);
    }
    return ans;
}

int main() {
    return 0;
}
