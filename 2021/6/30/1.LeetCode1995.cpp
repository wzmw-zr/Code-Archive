/*************************************************************************
	> File Name: 1.LeetCode1995.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月30日 星期三 00时20分03秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() = default;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null";
        string res = to_string(root->val);
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            auto temp = que.front();
            que.pop();
            if (temp->left) {
                res += "," + to_string(temp->left->val);
                que.push(temp->left);
            } else res += ",null";
            if (temp->right) {
                res += "," + to_string(temp->right->val);
                que.push(temp->right);
            } else res += ",null";
        }
        return res;
    }

    vector<string> split_str(string data) {
        vector<string> ans;
        for (int i = 0; data[i]; ) {
            string temp = "";
            while (data[i] && (data[i] != ',')) temp += data[i++];
            if (data[i]) i++;
            ans.push_back(temp);
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes = split_str(data);
        if (nodes[0] == "null") return nullptr;
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode *> que;
        que.push(root);
        int ind = 1;
        while (!que.empty()) {
            auto temp = que.front();
            que.pop();
            if (nodes[ind] != "null") {
                temp->left = new TreeNode(stoi(nodes[ind]));
                que.push(temp->left);
            }
            if (nodes[ind + 1] != "null") {
                temp->right = new TreeNode(stoi(nodes[ind + 1]));
                que.push(temp->right);
            }
            ind += 2;
        }
        return root;
    }
};

int main() {
    return 0;
}
