/*************************************************************************
	> File Name: 1.LeetCode1600.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月20日 星期日 00时12分33秒
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



class ThroneInheritance {
public:
    struct TreeNode {
        string name;
        vector<TreeNode *> children;
        bool alive;

        TreeNode() = default;
        TreeNode(string name) : name(name), alive(true) {}
    };

    unordered_map<string, TreeNode *> mp;
    string kingName;

    ThroneInheritance(string kingName) : kingName(kingName) {
        mp[kingName] = new TreeNode(kingName);
    }

    void birth(string parentName, string childName) {
        mp[childName] = new TreeNode(childName);
        mp[parentName]->children.push_back(mp[childName]);
    }

    void death(string name) {
        mp[name]->alive = false;
    }

    void dfs(TreeNode *root, vector<string> &ans) {
        if (!root) return ;
        if (root->alive) ans.push_back(root->name);
        for (auto child : root->children) dfs(child, ans);
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(mp[kingName], ans);
        return ans;
    }
};


int main() {
    return 0;
}
