/*************************************************************************
	> File Name: 2.LeetCode1707.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月23日 星期日 00时18分28秒
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
    int mmax;
    int ind;

    Node() = default;
    Node(int val, int mmax, int ind) : val(val), mmax(mmax), ind(ind) {}

    bool operator<(const Node &that) const {
        return this->mmax == that.mmax ? this->val < that.val : this->mmax < that.mmax;
    }
};


struct TreeNode {
    vector<TreeNode *> nodes;

    TreeNode() : nodes(2, nullptr) {}
};


struct DictTree {
    TreeNode *_root;
    
    DictTree() : _root(new TreeNode()) {}

    void insert(int num) {
        TreeNode *root = _root;
        vector<int> digits(32, 0);
        for (int i = 0; i < 32; i++) {
            digits[31 - i] = num & 1;
            num >>= 1;
        }
        for (int i = 0; i < 32; i++)
            cout << digits[i];
        cout << endl;
        for (int i = 0; i < 32; i++) {
            if (!root->nodes[digits[i]]) root->nodes[digits[i]] = new TreeNode();
            root = root->nodes[digits[i]];
        }
    }

    int query(int num) {
        int ans = 0;
        TreeNode *root = _root;
        vector<int> digits(32, 0);
        for (int i = 0; i < 32; i++) {
            digits[31 - i] = num & 1;
            num >>= 1;
        }
        for (int i = 0; i < 32; i++) {
            if (root->nodes[!digits[i]]) {
                ans += 1 << (31 - i);
                root = root->nodes[!digits[i]];
            } else if (root->nodes[digits[i]]) {
                root = root->nodes[digits[i]];
            } else return -1;
        }
        return ans;
    }
};


vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());
    vector<Node> nodes;
    int n = nums.size();
    int q = queries.size();
    vector<int> ans(q, -1);
    for (int i = 0; i < q; i++) 
        nodes.push_back(Node(queries[i][0], queries[i][1], i));
    sort(nodes.begin(), nodes.end());
    DictTree*root = new DictTree();
    int ind = 0;
    for (int i = 0; i < q; i++) {
        while ((ind < n) && (nums[ind] <= nodes[i].mmax)) 
            root->insert(nums[ind++]);
        ans[nodes[i].ind] = root->query(nodes[i].val);
    }
    return ans;
}

int main() {
    return 0;
}
