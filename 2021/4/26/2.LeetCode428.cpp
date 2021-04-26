/*************************************************************************
	> File Name: 2.LeetCode428.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月26日 星期一 22时07分32秒
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

struct Node {
    int val;
    vector<Node *> children;
    Node() = default;
    Node(int val) : val(val) {}
    Node(int val, vector<Node *> children) : val(val), children(children) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        queue<Node *> que;
        que.push(root);
        string ans = "";
        while (!que.empty()) {
            Node *temp = que.front();
            que.pop();
            ans += to_string(temp->val) + "," + to_string((int) temp->children.size()) + ",";
            for (auto &node : temp->children) que.push(node);
        }
        return ans;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        Node *root = nullptr;
        if (data.size() == 0) return root;
        int ind = 0;
        string root_val = "", root_child_num = "";
        while (data[ind] && data[ind] != ',') root_val += data[ind++];
        ind++;
        while (data[ind] && data[ind] != ',') root_child_num += data[ind++];
        ind++;
        queue<int> num_child;
        queue<Node *> nodes;
        num_child.push(stoi(root_child_num));
        root = new Node(stoi(root_val));
        nodes.push(root);
        while (!nodes.empty()) {
            int cnt = num_child.front();
            Node *_root = nodes.front();
            num_child.pop();
            nodes.pop();
            for (int i = 0; i < cnt; i++) {
                string child_val = "", cnt_child = "";
                while (data[ind] && data[ind] != ',') child_val += data[ind++];
                ind++;
                while (data[ind] && data[ind] != ',') cnt_child += data[ind++];
                ind++;
                Node *temp = new Node(stoi(child_val));
                _root->children.push_back(temp);
                nodes.push(temp);
                num_child.push(stoi(cnt_child));
            }
        }
        return root;
    }
};

int main() {
    return 0;
}
