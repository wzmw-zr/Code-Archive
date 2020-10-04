/*************************************************************************
	> File Name: 8.LeetCode863.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月04日 星期日 15时26分24秒
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
    TreeNode() = default;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

struct Node {
    bool has_target;
    int distance;

    Node() = default;
    Node(bool has_target) : has_target(has_target) {}
    Node(bool has_target, int distance) : has_target(has_target), distance(distance) {}
};

typedef pair<bool, int> PBI;

void KLevelChild(TreeNode *root, int K, vector<int> &ans) {
    if (!root) return ;
    if (!K) {
        ans.push_back(root->val);
        return ;
    }
    KLevelChild(root->left, K - 1, ans);
    KLevelChild(root->right, K - 1, ans);
}

PBI dfs(TreeNode *root, TreeNode *target, int K, vector<int> &ans) {
    if (!root) return PBI(false, 0);
    if (root == target) return PBI(true, 0);
    PBI left = dfs(root->left, target, K, ans);
    PBI right = dfs(root->right, target, K, ans);
    if (left.first && K - left.second - 1 >= 0) {
        if (K - left.second - 1 == 0) ans.push_back(root->val);
        else KLevelChild(root->right, K - left.second - 2, ans);
        return PBI(true, left.second + 1);
    }
    if (right.first && K - right.second - 1 >= 0) {
        if (K - right.second - 1 == 0) ans.push_back(root->val);
        else KLevelChild(root->left, K - right.second - 2, ans);
        return PBI(true, right.second + 1);
    }
    return PBI(false, 0);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> ans;
    KLevelChild(target, K, ans);
    dfs(root, target, K, ans);
    return ans;
}

int main() {
    return 0;
}
