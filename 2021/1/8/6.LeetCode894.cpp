/*************************************************************************
	> File Name: 6.LeetCode894.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月08日 星期五 16时48分00秒
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

unordered_map<int, vector<TreeNode *>> mp;

TreeNode *duplicate_tree(TreeNode *root) {
    if (!root) return nullptr;
    TreeNode *ans = new TreeNode();
    ans->left = duplicate_tree(root->left);
    ans->right = duplicate_tree(root->right);
    return ans;
}

vector<TreeNode*> allPossibleFBT(int N) {
    if (!(N & 1)) return vector<TreeNode *>(0);
    if (N == 1) {
        mp[N] = vector<TreeNode *>({new TreeNode(0)});
        return mp[N];
    }
    TreeNode *root = new TreeNode(0);
    vector<TreeNode *> temp;
    for (int j = 1; j < N - 1; j += 2) {
        vector<TreeNode *> left, right;
        if (mp.count(j)) left = mp[j];
        else left = allPossibleFBT(j);
        if (mp.count(N - 1 - j)) right = mp[N - 1 - j];
        else right = allPossibleFBT(N - 1 - j);
        for (auto &x : left) {
            for (auto &y : right) {
                root->left = x;
                root->right = y;
                temp.push_back(duplicate_tree(root));
            }
        }
    }
    delete root;
    if (!mp.count(N)) mp[N] = temp;
    return temp;
}

int main() {
    return 0;
}
