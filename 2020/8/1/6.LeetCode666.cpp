/*************************************************************************
	> File Name: 6.LeetCode666.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月01日 星期六 18时14分20秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<functional>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void getPathSum(TreeNode *root, int &res, int sum) {
    if (!root) return;
    if (!root->left && !root->right) {
        sum += root->val;
        res += sum;
        return ;
    }
    getPathSum(root->left, res, sum + root->val);
    getPathSum(root->right, res, sum + root->val);
}

int pathSum(vector<int>& nums) {
    unordered_map<int, TreeNode *> mp;
    function<bool(int, int)> cmp = [](int x, int y) -> bool {
        int x_h = x / 100, x_m = (x % 100) / 10, x_l = x % 10;
        int y_h = x / 100, y_m = (y % 100) / 10, y_l = y % 10;
        if (x_h - y_h) return x_h < y_h;
        return x_m < y_m;
    };
    sort(nums.begin(), nums.end(), cmp);
    TreeNode *root = nullptr;
    for (int i = 0; i < nums.size(); i++) {
        int h = nums[i] / 100, m = (nums[i] % 100) / 10, l = nums[i] % 10;
        int ind = pow(2, h - 1) + m - 1;
        if (h == 1) {
            root = new TreeNode(l);
            mp[ind] = root;
            continue;
        }
        TreeNode *tmp = new TreeNode(l);
        if (ind & 1) mp[(ind >> 1)]->right = tmp;
        else mp[(ind >> 1)]->left = tmp;
        mp[ind] = tmp;
    }
    int res = 0;
    getPathSum(root, res, 0);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << pathSum(nums) << endl;
    return 0;
}
