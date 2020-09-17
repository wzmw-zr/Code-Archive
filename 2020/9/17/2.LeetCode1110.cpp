/*************************************************************************
	> File Name: 2.LeetCode1110.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月17日 星期四 08时20分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *delNodes(TreeNode *root, int num, vector<TreeNode *> &ans) {
    if (!root) return NULL;
    root->left = delNodes(root->left, num, ans);
    root->right = delNodes(root->right, num, ans);
    if (root->val - num) return root;
    if (root->left) ans.push_back(root->left);
    if (root->right) ans.push_back(root->right);
    return NULL;
}

void delNodes(vector<int> &to_delete, vector<TreeNode *> &ans) {
    for (auto &x : to_delete) {
        for (int i = 0; i < ans.size(); i++) {
            TreeNode *temp = delNodes(ans[i], x, ans);
            cout << x << " " << (!temp ? "delete root" : "not delete root") << endl;
            if (temp) continue; 
            for (int j = 0; j < ans.size(); j++) {
                cout << ans[i] << " " << ans[j] << endl;
                if (ans[i] == ans[j]) {
                    ans.erase(ans.begin() + j);
                    break;
                }
            }
            break;
        }
    }
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode *> ans;
    ans.push_back(root);
    delNodes(to_delete, ans);
    return ans;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    vector<int> to_delete = {2, 1};
    vector<TreeNode *> ans = delNodes(root, to_delete);
    cout << ans.size() << endl;
    return 0;
}
