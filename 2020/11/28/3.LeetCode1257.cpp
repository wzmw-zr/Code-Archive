/*************************************************************************
	> File Name: 3.LeetCode1257.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月28日 星期六 08时31分36秒
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
    string val;
    TreeNode *parent;
    TreeNode() : val(""), parent(nullptr) {}
    TreeNode(string s) : val(s), parent(nullptr) {}
};

vector<TreeNode *> get_path(TreeNode *child) {
    vector<TreeNode *> ans;
    while (child) {
        ans.push_back(child);
        child = child->parent;
    }
    return ans;
}

string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
    unordered_map<string, TreeNode *> mp;
    for (auto &x : regions) {
        for (auto &y : x) {
            if (mp.count(y)) continue;
            mp[y] = new TreeNode(y);
        }
    }
    for (auto &x : regions) {
        int n = x.size();
        for (int i = 1; i < n; i++) {
            mp[x[i]]->parent = mp[x[0]];
        }
    }
    vector<TreeNode *> path_1 = get_path(mp[region1]);
    vector<TreeNode *> path_2 = get_path(mp[region2]);
    TreeNode *ans;
    int len_1 = path_1.size(), len_2 = path_2.size();
    for (int i = len_1 - 1, j = len_2 - 1; i >= 0 && j >= 0; i--, j--) {
        if (path_1[i] != path_2[j]) break;
        ans = path_1[i];
    }
    return ans->val;
}

int main() {
    return 0;
}
