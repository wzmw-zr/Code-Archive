/*************************************************************************
	> File Name: 4.LeetCode1740.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月28日 星期四 19时07分53秒
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<int> dfs(TreeNode *root, int p, int q, int &ans) {
    if (!root) return vector<int>(4, 0);
    auto left = dfs(root->left, p, q, ans);
    auto right = dfs(root->right, p, q, ans);
    vector<int> ret(4, 0);
    if (root->val == p) ret[0] = ret[1] = 1;
    if (root->val == q) ret[2] = ret[3] = 1;
    if (!left[0] && !left[2] && !right[0] && !right[2]) return ret;
    if (left[0] && left[2]) return left;
    if (right[0] && right[2]) return right;
    if (left[0] && right[2]) {
        ret[0] = ret[2] = 1;
        ans = left[1] + right[3];
        ret[1] = left[1] + 1;
        ret[3] = right[3] + 1;
        return ret;
    }
    if (left[2] && right[0]) {
        ret[0] = ret[2] = 1;
        ans = left[3] + right[1];
        ret[1] = right[1] + 1;
        ret[3] = left[3] + 1;
        return ret;
    }
    if (left[0] || right[0]) {
        if (ret[2]) {
            ans = max(left[1], right[1]);
            ret[0] = 1;
            ret[1] = ans + 1;
            return ret;
        }
        ret[0] = 1;
        ret[1] = max(left[1], right[1]) + 1;
        return ret;
    }
    if (ret[0]) {
        ans = max(left[3], right[3]);
        ret[2] = 1;
        ret[3] = ans + 1;
        return ret;
    }
    ret[2] = 1;
    ret[3] = max(left[3], right[3]) + 1;
    return ret;
}


int findDistance(TreeNode* root, int p, int q) {
    int ans = 0;
    dfs(root, p, q, ans);
    return ans;
}

int main() {
    return 0;
}
