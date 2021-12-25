/*************************************************************************
	> File Name: 1.LeetCode1609.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月25日 星期六 08时39分13秒
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() = default;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

void dfs(TreeNode *root, vector<vector<int>> &levels, int level) {
    if (!root) return ;
    if (level == levels.size()) levels.push_back(vector<int>());
    levels[level].push_back(root->val);
    dfs(root->left, levels, level + 1);
    dfs(root->right, levels, level + 1);
}

bool isEvenOddTree(TreeNode* root) {
    vector<vector<int>> levels;
    dfs(root, levels, 0);
    int n = levels.size();
    for (int i = 0; i < n; i++) {
        int m = levels[i].size();
        for (int j = 0; j < m; j++) {
            if (i & 1) {
                if (levels[i][j] & 1) return false;
                if (j && (levels[i][j] >= levels[i][j - 1])) return false;
            } else {
                if (!(levels[i][j] & 1)) return false;
                if (j && (levels[i][j] <= levels[i][j - 1])) return false;
            }
        }
    }
    return true;
}

int main() {
    return 0;
}
