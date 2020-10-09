/*************************************************************************
	> File Name: 2.LeetCode536.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月09日 星期五 10时47分24秒
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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* str2tree(string s) {
    cout << s << endl;
    if (s == "") return nullptr;
    if (s.find("(") == string::npos) return new TreeNode(stoi(s));
    int ind = s.find_first_of("("), end;
    TreeNode *root = new TreeNode(stoi(s.substr(0, ind)));
    stack<int> st;
    for (int i = ind; s[i]; i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            st.pop();
            if (st.empty()) {
                end = i;
                break;
            }
        } else continue;
    }
    root->left = str2tree(s.substr(ind + 1, end - ind - 1));
    if (end + 2 > s.size()) root->right = nullptr;
    else root->right = str2tree(s.substr(end + 2, s.size() - 3 - end));
    return root;
}

void dfs(TreeNode *root) {
    if (!root) return ;
    cout << root->val;
    dfs(root->left);
    dfs(root->right);
}

int main() {
    string s;
    cin >> s;
    TreeNode *root = str2tree(s);
    dfs(root);
    return 0;
}
