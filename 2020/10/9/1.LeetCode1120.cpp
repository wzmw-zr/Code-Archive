/*************************************************************************
	> File Name: 1.LeetCode1120.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月09日 星期五 08时14分03秒
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
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

typedef pair<double, int> PDI;

PDI dfs(TreeNode *root, double &ans) {
    if (!root) return PDI(0.0, 0);
    if (!root->left && !root->right) {
        ans = max(ans, root->val * 1.0);
        return PDI(root->val * 1.0, 1);
    }
    PDI left = dfs(root->left, ans);
    PDI right = dfs(root->right, ans);
    double sum = left.first * left.second + right.first * right.second + root->val * 1.0;
    int cnt = left.second + right.second + 1;
    ans = max(ans, sum / cnt);
    return PDI(sum / cnt, cnt);
}

double maximumAverageSubtree(TreeNode* root) {
    double ans = 0.0;
    dfs(root, ans);
    return ans;
}

int main() {
    return 0;
}
