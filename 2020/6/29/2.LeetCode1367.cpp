/*************************************************************************
	> File Name: 1.LeetCode1367.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月29日 星期一 07时04分09秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


bool isSubPath(ListNode *head, TreeNode *root) {
    if (!head && !root) return true;
    if (head && !root) return false;
    if (head->val != root->val) 
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    return isSubPath(head->next, root->left) || isSubPath(head->next, root->right);
}

int main() {
    return 0;
}
