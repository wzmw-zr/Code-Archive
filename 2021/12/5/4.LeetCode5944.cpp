/*************************************************************************
	> File Name: 4.LeetCode5944.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月05日 星期日 10时57分22秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// TLE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string find_path(TreeNode *root, int target) {
    if (!root || root->val == target) return "";
    if (root->val < target) return "R" + find_path(root->right, target);
    return "L" + find_path(root->left, target);
}

map<int, string> dfs(TreeNode *root, string &ans, int startValue, int destValue) {
    if (!root) return map<int, string>();
    auto left = dfs(root->left, ans, startValue, destValue);
    auto right = dfs(root->right, ans, startValue, destValue);
    if (ans.size()) return map<int, string>();
    for (auto &&[val, path] : left) left[val] += "L";
    for (auto &&[val, path] : right) right[val] += "R";
    left.merge(right);
    left[root->val] = "";
    if (!left.count(startValue) || !left.count(destValue)) return left;
    string dest_path = left[destValue];
    reverse(dest_path.begin(), dest_path.end());
    ans = string(left[startValue].size(), 'U') + dest_path;
    return left;
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    string ans;
    dfs(root, ans, startValue, destValue);
    return ans;
}

int main() {
    return 0;
}
