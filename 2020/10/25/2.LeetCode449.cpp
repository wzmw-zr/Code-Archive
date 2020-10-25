/*************************************************************************
	> File Name: 2.LeetCode449.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月25日 星期日 07时43分05秒
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
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string ans = "";
    queue<TreeNode *> que;
    if (root) {
        que.push(root);
        ans += to_string(root->val);
    }
    while (!que.empty()) {
        TreeNode *temp = que.front();
        que.pop();
        if (temp->left) {
            ans += "," + to_string(temp->left->val);
            que.push(temp->left);
        }
        else ans += ",null";
        if (temp->right) {
            ans += "," + to_string(temp->right->val);
            que.push(temp->right);
        } else ans += ",null";
    }
    int len = ans.size();
    while (ans[len - 1] && !(ans[len - 1] >= '0' && ans[len - 1] <= '9')) {
        ans.erase(ans.end() - 1);
        len--;
    }
    ans = "[" + ans + "]";
    return ans;
}

TreeNode *get_node(string &data, int &ind) {
    TreeNode *ret = nullptr;
    while (data[ind]) {
        if (data[ind] == ',') ind++;
        else {
            int left = ind;
            while (data[ind] && data[ind] != ',') ind++;
            string s_t = data.substr(left, ind - left);
            if (s_t != "null") ret = new TreeNode(stoi(s_t));
            break;
        }
    }
    return ret;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    TreeNode *root = nullptr;
    queue<TreeNode *> que;
    data.erase(data.end() - 1);
    data.erase(data.begin());
    if (data.size() == 0) return nullptr;
    int ind = 0;
    int flag = 0;
    root = get_node(data, ind);
    que.push(root);
    while (!que.empty()) {
        TreeNode *temp = que.front();
        que.pop();
        temp->left = get_node(data, ind);
        temp->right = get_node(data, ind);
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
    return root;
}

int main() {
    string data;
    cin >> data;
    TreeNode *root = deserialize(data);
    cout << serialize(root) << endl;
    return 0;
}
