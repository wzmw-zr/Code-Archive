/*************************************************************************
	> File Name: 1.LeetCode987.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月31日 星期六 00时06分48秒
 ************************************************************************/

#include <iostream>
#include <tuple>
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using PII = pair<int, int>;

void dfs(TreeNode *root, int row, int col, map<int, vector<PII>> &mp) {
    if (!root) return ;
    if (!mp.count(col)) mp[col] = vector<PII>{};
    mp[col].push_back(PII(row, root->val));
    dfs(root->left, row + 1, col - 1, mp);
    dfs(root->right, row + 1, col + 1, mp);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<PII>> mp;
    dfs(root, 0, 0, mp);
    vector<vector<int>> ans;
    for (auto &&[col, val] : mp) {
        sort(val.begin(), val.end());   
        vector<int> temp;
        for (auto &&[row, v] : val) temp.push_back(v);
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    return 0;
}
