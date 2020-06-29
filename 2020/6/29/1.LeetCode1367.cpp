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

int GetListLen(ListNode *head) {
    ListNode *tmp = head;
    int len = 0;
    while (tmp) {
        len++;
        tmp = tmp->next;
    }
    return len;
}

bool check(ListNode *head, vector<int> &path, int len) {
    int path_len = path.size();
    for (int i = 0; i < path_len - len; i++) {
        ListNode *tmp = head;
        for (int j = 0; j < len; j++) {
            if (path[i + j] != tmp->val) break;
            tmp = tmp->next;
        }
        if (tmp) continue;
        return true;
    }
    return false;
}

bool isSubPath(ListNode *head, TreeNode *root, vector<int> &path, int len) {
    if (!root) return check(head, path, len);
    path.push_back(root->val); 
    if (isSubPath(head, root->left, path, len) || isSubPath(head, root->right, path, len)) {
        path.pop_back();
        return true;
    }
    path.pop_back();
    return false;
}

bool isSubPath(ListNode *head, TreeNode *root) {
    vector<int> path;
    int len = GetListLen(head);
    return isSubPath(head, root, path, len);
}

int main() {
    return 0;
}
