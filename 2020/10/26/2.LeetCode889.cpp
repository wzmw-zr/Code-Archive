/*************************************************************************
	> File Name: 2.LeetCode889.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月26日 星期一 08时03分26秒
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

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

int check(vector<int> &pre, int l_1, int r_1 ,vector<int> &post, int l_2, int r_2) {
    set<int> st;
    for (int i = l_1; i <= r_1; i++) st.insert(pre[i]);
    for (int i = l_2; i <= r_2; i++) {
        if (st.count(post[i])) continue;
        return 0;
    }
    return 1;
}

TreeNode *build(vector<int> &pre, int l_1, int r_1, vector<int> &post, int l_2, int r_2) {
    if (l_1 > r_1) return NULL;
    if (l_1 == r_1) return new TreeNode(pre[l_1]);
    TreeNode *root = new TreeNode(pre[l_1]);
    int temp = pre[l_1 + 1], i;
    for (i = l_2; i <= r_2 - 1; i++) {
        if (temp == post[i]) break;
        continue;
    }
    int len = i - l_2 + 1;
    root->left = build(pre, l_1 + 1, l_1 + len, post, l_2, l_2 + len - 1);
    root->right = build(pre, l_1 + len + 1, r_1, post, l_2 + len, r_2 - 1);
    return root;
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int len = pre.size();
    return build(pre, 0, len - 1, post, 0, len - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> pre(n, 0), post(n, 0);
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    constructFromPrePost(pre, post);
    return 0;
}
