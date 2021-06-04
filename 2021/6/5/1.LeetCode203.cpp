/*************************************************************************
	> File Name: 1.LeetCode203.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月05日 星期六 00时03分16秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode *node = new ListNode(0, head);
    ListNode *temp = node;
    while (temp && temp->next) {
        if (temp->next->val != val) 
            temp = temp->next;
        else {
            ListNode *t = temp->next;
            temp->next = t->next;
            delete t;
        }
    }
    return node->next;
}

int main() {
    return 0;
}
