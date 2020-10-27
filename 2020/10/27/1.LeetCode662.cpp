/*************************************************************************
	> File Name: 1.LeetCode662.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月27日 星期二 09时11分00秒
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

struct BigInt {
    vector<int> digit;
    BigInt() {
        this->digit.push_back(0);
    }
    BigInt(int n) {
        while (n) {
            digit.push_back(n % 10);
            n /= 10;
        }
    }
    BigInt(const BigInt &a) {
        this->digit = a.digit;
    }
    void update() {
        for (int i = 0; i < this->digit.size(); i++) {
            if (this->digit[i] < 10) continue;
            if (i + 1 == this->digit.size()) this->digit.push_back(0);
            this->digit[i + 1] += this->digit[i] / 10;
            this->digit[i] %= 10;
        }
    }

    BigInt operator*(int n) {
        for (int &x : this->digit) x *= n;
        update();
        return *this;
    }

    BigInt operator+(int n) {
        this->digit[0] += n;
        update();
        return *this;
    }

};

void dfs(TreeNode *root, vector<vector<BigInt>> &nodes, int level, BigInt ind) {
    if (!root) return ;
    if (nodes.size() == level) nodes.push_back(vector<BigInt>(0));
    nodes[level].push_back(BigInt(ind));
    dfs(root->left, nodes, level + 1, ind * 2);
    dfs(root->right, nodes, level + 1, ind * 2 + 1);
}

int widthOfBinaryTree(TreeNode* root) {        
    vector<vector<BigInt>> nodes;
    //dfs(root, nodes, 0, 1);
    int ans = 0;
    for (auto &x : nodes) {
        //sort(x.begin(), x.end());
        //ans = max(ans, (x.size() == 1) ? 0 : x[x.size() - 1] - x[0] + 1);
    }
    return ans;
}

int main() {
    return 0;
}
