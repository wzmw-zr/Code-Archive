/*************************************************************************
	> File Name: 7.LeetCode894.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月08日 星期五 17时06分25秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() = default;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

unordered_map<int, vector<TreeNode *>> mp;

TreeNode *duplicate_tree(TreeNode *root) {
    if (!root) return nullptr;
    TreeNode *ans = new TreeNode(0);
    ans->left = duplicate_tree(root->left);
    ans->right = duplicate_tree(root->right);
    return ans;
}

vector<TreeNode*> allPossibleFBT(int N) {
    if (!(N & 1)) return vector<TreeNode *>(0);
    mp[1] = vector<TreeNode *>({new TreeNode(0)});
    TreeNode *root = new TreeNode(0);
    for (int i = 3; i <= N; i += 2) {
        vector<TreeNode *> temp;
        for (int j = 1; j < i - 1; j += 2) {
            for (auto &x : mp[j]) {
                for (auto &y : mp[i - 1 - j]) {
                    root->left = x;
                    root->right = y;
                    temp.push_back(duplicate_tree(root));
                }
            }
        }
        mp[i] = temp;
    }
    return mp[N];
}

int main() {
    return 0;
}
