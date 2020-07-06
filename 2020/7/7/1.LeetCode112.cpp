/*************************************************************************
	> File Name: 1.LeetCode112.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月07日 星期二 00时02分53秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return sum ? false : true;
    if (hasPathSum(root->left, sum - root->val)) return true;
    return hasPathSum(root->right, sum - root->val);
}

int main() {
    return 0;
}
