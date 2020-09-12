/*************************************************************************
	> File Name: 4.LeetCode654.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月12日 星期六 18时46分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

TreeNode *constructMaximumBinaryTree(vector<int> &nums, int left, int right) {
    if (left > right) return NULL;
    if (left == right) return new TreeNode(nums[left]);
    int ind = left, num = nums[left];
    for (int i = left; i <= right; i++) {
        if (nums[i] > num) {
            ind = i, num = nums[i];
        }
    }
    TreeNode *temp = new TreeNode(num);
    temp->left = constructMaximumBinaryTree(nums, left, ind - 1);
    temp->right = constructMaximumBinaryTree(nums, ind + 1, right);
    return temp;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    return constructMaximumBinaryTree(nums, l, r);
}

int main() {
    return 0;
}
