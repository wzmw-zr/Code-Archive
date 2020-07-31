/*************************************************************************
	> File Name: 1.LeetCode437.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月31日 星期五 07时35分07秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef pair<TreeNode *, TreeNode *> PPP;


void handle(vector<TreeNode *> &node, set<PPP> &st, int sum) {
    vector<int> pre_sum(node.size() + 1, 0);
    for (int i = 1; i <= node.size(); i++) {
        pre_sum[i] = pre_sum[i - 1] + node[i - 1]->val;
    }
    for (int i = 1; i <= node.size(); i++) {
        for (int j = i; j <= node.size(); j++) {
            if (pre_sum[j] - pre_sum[i - 1] != sum) continue;
            st.insert(PPP(node[i - 1], node[j - 1]));
        }
    }
}

void countPath(vector<TreeNode *> &node, set<PPP> &st, TreeNode *root, int sum) {
    if (!root) {
        handle(node, st, sum);
        return ;
    }
    node.push_back(root);
    countPath(node, st, root->left, sum);
    countPath(node, st, root->right, sum);
    node.pop_back();
}

int pathSum(TreeNode* root, int sum) {
    vector<TreeNode *> node;
    set<PPP> st;
    countPath(node, st, root, sum);
    return st.size();
}

int main() {
    return 0;
}
