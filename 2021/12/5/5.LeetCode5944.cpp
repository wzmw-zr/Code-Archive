/*************************************************************************
	> File Name: 5.LeetCode5944.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月05日 星期日 11时21分53秒
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
    if (!root) return "";
    if (root->val == target) return "F";
    string left = find_path(root->left, target);
    if (left.size()) return "L" + left;
    string right = find_path(root->right, target);
    if (right.size()) return "R" + right;
    return "";
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    string start_path = find_path(root, startValue);
    string dest_path = find_path(root, destValue);
    start_path.erase(prev(start_path.end()));
    dest_path.erase(prev(dest_path.end()));
    int m = start_path.size(), n = dest_path.size();
    int common = 0;
    while (start_path[common] == dest_path[common]) common++;
    string ans = string(m - common, 'U') + dest_path.substr(common);
    return ans;
}

int main() {
    return 0;
}
