/*************************************************************************
	> File Name: 1.LeetCode95.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月21日 星期二 00时09分09秒
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

vector<TreeNode *> buildTrees(int left, int right) {
    vector<TreeNode *> ret;
    if (left < right) {
        ret.push_back(NULL);
        return ret;
    }
    if (left == right) {
        ret.push_back(new TreeNode(left));
        return ret;
    }
    for (int i = left; i <= right; i++) {
        vector<TreeNode *> res_l = buildTrees(left, i - 1);
        vector<TreeNode *> res_r = buildTrees(i + 1, right);
        for (int j = 0; j < res_l.size(); j++) {
            for (int k = 0; k < res_r.size(); k++) {
                TreeNode *now = new TreeNode(i);
                now->left = res_l[j];
                now->right = res_r[k];
                ret.push_back(now);
            }
        }
    }
    return ret;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode *> res;
    for (int i = 1; i <= n; i++) {
        vector<TreeNode *> res_l = buildTrees(1, i - 1);
        vector<TreeNode *> res_r = buildTrees(i + 1, n);
        for (int j = 0; j < res_l.size(); j++) {
            for (int k = 0; k < res_r.size(); k++) {
                TreeNode *now = new TreeNode(i);
                now->left = res_l[j];
                now->right = res_r[k];
                res.push_back(now);
            }
        }
    }
    return res;
}

int main() {
    return 0;
}
