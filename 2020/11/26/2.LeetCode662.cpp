/*************************************************************************
	> File Name: 2.LeetCode662.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月26日 星期四 12时14分52秒
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
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct BigInterger {
    vector<int> digit;
    BigInterger() = default;
    BigInterger(int x) {
        do {
            digit.push_back(x % 10);
            x /= 10;
        } while (x);
    }
    BigInterger(BigInterger &a) : digit(a.digit) {}
    BigInterger(BigInterger &&a) : digit(a.digit) {}

    void update() {
        for (int i = 0; i < digit.size(); i++) {
            if (digit[i] < 10) continue;
            if (i + 1 == digit.size()) digit.push_back(0);
            digit[i + 1] += digit[i] / 10;
            digit[i] %= 10;
        }
    }

    BigInterger operator*(int a) {
        for (int x : digit) x *= a;
        update();
        return *this;
    }

    BigInterger operator+(int a) {
        digit[0] += a;
        update();
        return *this;
    }

    bool operator<(const BigInterger & a) const {
        int len_1 = this->digit.size(), len_2 = a.digit.size();
        if (len_1 > len_2) return false;
        if (len_2 > len_1) return true;
        for (int i = len_1 - 1; i >= 0; i--) {
            if (this->digit[i] == a.digit[i]) continue;
            return this->digit[i] < a.digit[i] ? true : false;
        }
        return true;
    }
};

void dfs(TreeNode *root, vector<vector<int>> &layer, int level, int ind) {
    if (!root) return ;
    if (layer.size() == level) layer.push_back(vector<int>(0));
    layer[level].push_back(ind);
    dfs(root->left, layer, level + 1, ind * 2);
    dfs(root->right, layer, level + 1, ind * 2 + 1);
}

int widthOfBinaryTree(TreeNode* root) {
    vector<vector<int>> layer;
    dfs(root, layer, 0, 1);
    int ans = 0;
    for (auto x : layer) sort(x.begin(), x.end());
    for (auto x : layer) {
        if (x.size() == 1) continue;
        ans = max(ans, x[x.size() - 1] - x[0]);
    }
    return ans;
}

int main() {
    return 0;
}
