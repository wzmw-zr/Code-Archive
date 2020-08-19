/*************************************************************************
	> File Name: 1.LeetCode109.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月18日 星期二 08时11分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct NewNode {
    int val;
    int height;
    NewNode *left;
    NewNode *right;
    NewNode();
    NewNode(int x);
};

NewNode __NIL, *NIL;

NewNode::NewNode() : val(0), height(0), left(this), right(this) {}
NewNode::NewNode(int x) : val(x), height(1), left(this), right(this) {}

NewNode *update(NewNode *root) {
    if (root == NIL) return NIL;
    root->height = max(root->left->height, root->right->height) + 1;
    return root;
}

NewNode *left_rotate(NewNode *root) {
    NewNode *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return update(temp);
}

NewNode *right_rotate(NewNode *root) {
    NewNode *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return update(temp);
}

NewNode *maintain(NewNode *root) {
    int left = root->left->height, right = root->right->height;
    if (abs(left - right) <= 1) return update(root);
    if (left > right) {
        if (root->left->right->height > root->left->left->height) root->left = left_rotate(root->left);
        root = right_rotate(root);
    } else {
        if (root->right->left->height > root->right->right->height) root->right = right_rotate(root->right);
        root = left_rotate(root);
    }
    return update(root);
}

NewNode *insert(NewNode *root, int val) {
    if (root == NIL) {
        NewNode *res = new NewNode(val);
        res->left = NIL; 
        res->right = NIL;
        return res;
    }
    if (root->val == val) return root;
    if (root->val < val) {
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    }
    return maintain(root);
}

TreeNode *build(TreeNode *root, NewNode *n_root) {
    if (n_root == NIL) return nullptr;
    TreeNode *temp = new TreeNode(n_root->val);
    temp->left = build(root->left, n_root->left);
    temp->right = build(root->right, n_root->right);
    return temp;
}

TreeNode* sortedListToBST(ListNode* head) {
    NIL = &__NIL;
    NIL->left = NIL, NIL->right = NIL;
    NewNode *root = NIL;
    TreeNode *ret = nullptr;
    while (head && head->next) {
        root = insert(root, head->val);
        head = head->next;
    }
    ret = build(ret, root);
    return ret;
}

void show(TreeNode *root) {
    if (!root) return ;
    show(root->left);
    cout << root->val << " ";
    show(root->right);
}


int main() {
    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    TreeNode *root = sortedListToBST(head);
    cout << endl;
    return 0;
}
