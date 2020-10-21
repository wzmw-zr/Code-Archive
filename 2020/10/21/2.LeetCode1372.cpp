/*************************************************************************
	> File Name: 2.LeetCode1372.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月21日 星期三 08时32分26秒
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

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

typedef pair<int, int> PII;

PII dfs(TreeNode *root, int &ans) {
    if (!root) return PII(-1, -1);
    if (!root->left && !root->right) {
        ans = max(ans, 0);
        return PII(0, 0);
    }
    PII left = dfs(root->left, ans);
    PII right = dfs(root->right, ans);
    PII ret(1 + left.second, 1 + right.first);
    ans = max(ans, 1 +  max(left.second, right.first));
    return ret;
}

int longestZigZag(TreeNode* root) {
    int ans = -1;
    dfs(root, ans);
    return ans;
}

int main() {
    return 0;
}
