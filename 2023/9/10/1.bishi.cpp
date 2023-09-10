/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月10日 星期日 21时11分17秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct TreeNode {
 int val;
 struct TreeNode *left;
 struct TreeNode *right;
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回节点权值1个数比0的个数多一的路径数
     * @param root TreeNode类 权值为0和1的二叉树根节点
     * @return int整型
     */
    void dfs(TreeNode *root, int &ans, int dis) {
        if (!root)
            return ;
        dis += root->val == 1 ? 1 : -1;
        if (!root->left && !root->right) {
            if (dis == 1)
                ans++;
            return ;
        }
        dfs(root->left, ans, dis);
        dfs(root->right, ans, dis);
    }
    int pathNumber(TreeNode* root) {
        // write code here
        int ans = 0, dis = 0;
        dfs(root, ans, dis);
        return ans;
    }
};
