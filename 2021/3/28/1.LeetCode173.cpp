/*************************************************************************
	> File Name: 1.LeetCode173.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月28日 星期日 00时01分50秒
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    vector<int> nums;
    int ind;

    BSTIterator(TreeNode* root) {
        ind = 0;
        dfs(root);
    }

    void dfs(TreeNode *root) {
        if (!root) return ;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }

    int next() {
        return nums[ind++];
    }

    bool hasNext() {
        return ind < (int) nums.size();
    }
};


int main() {
    return 0;
}
