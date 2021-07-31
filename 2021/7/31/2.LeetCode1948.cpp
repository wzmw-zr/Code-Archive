/*************************************************************************
	> File Name: 2.LeetCode1948.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月31日 星期六 21时01分19秒
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

// WA
struct TreeNode {
    string val;
    map<string, TreeNode *> children;
    TreeNode() = default;
    TreeNode(string _val) : val(_val) {};
};

void insert(TreeNode *root, vector<string> &path) {
    for (string &p : path) {
        if (!root->children.count(p)) root->children[p] = new TreeNode(p);
        root = root->children[p];
    }
}

void erase(TreeNode *root) {
    if (!root) return ;
    for (auto &&[n_val, n_node] : root->children) erase(n_node);
    delete root;
    return ;
}

string dfs(TreeNode *root, unordered_set<string> &st) {
    if (!root) return "";
    string res = "";
    for (auto iter = root->children.begin(); iter != root->children.end(); ) {
        string temp = dfs(iter->second, st);
        res += temp;
        if (st.count(temp)) {
            erase(iter->second);
            iter = root->children.erase(iter);
        } else iter++;
    }
    res += root->val;
    st.insert(res);
    return res;
}

void get_pathes(TreeNode *root, vector<vector<string>> &ans, vector<string> &path) {
    if (!root) return ;
    for (auto &&[val, ptr] : root->children) {
        path.push_back(val);
        ans.push_back(path);
        get_pathes(ptr, ans, path);
        path.pop_back();
    }
}

vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    TreeNode *root = new TreeNode("");
    for (auto path : paths) insert(root, path);
    unordered_set<string> st;
    dfs(root, st);
    vector<vector<string>> ans;
    vector<string> path;
    get_pathes(root, ans, path);
    return ans;
}

int main() {
    return 0;
}
