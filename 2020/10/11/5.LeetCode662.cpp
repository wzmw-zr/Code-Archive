/*************************************************************************
	> File Name: 5.LeetCode662.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月11日 星期日 18时26分28秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
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
    vector<long> digit;   

    BigInt(int x) {
        do {
            this->digit.push_back(x % 10);
            x /= 10;
        } while(x);
    }

    BigInt(BigInt &b) {
        this->digit = b.digit;
    }

    BigInt(vector<long> &array) {
        this->digit = array;
    }

    void refresh() {
        for (int i = 0; i < this->digit.size(); i++) {
            if (this->digit[i] < 10) continue;
            if (i + 1 == this->digit.size()) this->digit.push_back(0);
            this->digit[i + 1] += this->digit[i] / 10;
            this->digit[i] %= 10;
        }
    }

    BigInt operator+(int x) {
        this->digit[0] += x;
        this->refresh();
        return this->digit;
    }

    BigInt operator*(int x) {
        for (int i = 0; i < this->digit.size(); i++) this->digit[i] *= i;
        this->refresh();
        return this->digit;
    }

    int operator-(BigInt &b) {
        long ten_pow = pow(10, this->digit.size() - 1);
        return ten_pow;
    }
};

void dfs(TreeNode *root, vector<vector<long>> &node, long level, long ind) {
    if (level >= node.size())  return ;
    if (!root) return ;
    node[level].push_back(ind);
    dfs(root->left, node, level + 1, 2 * ind);
    dfs(root->right, node, level + 1, 2 * ind + 1);
}

long getLevel(TreeNode *root) {
    if (!root) return 0;
    return max(getLevel(root->left), getLevel(root->right)) + 1;
}

int widthOfBinaryTree(TreeNode* root) {
    long level = getLevel(root);
    vector<vector<long>> node(level);
    dfs(root, node, 0, 1);
    long ans = 0;
    for (auto &x : node) {
        sort(x.begin(), x.end());
        ans = max(ans, x[x.size() - 1] - x[0] + 1);
    }
    return ans;
}

int main() {
    return 0;
}
