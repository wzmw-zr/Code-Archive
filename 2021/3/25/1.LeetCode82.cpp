/*************************************************************************
	> File Name: 1.LeetCode82.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月25日 星期四 00时02分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *h = new ListNode();
    ListNode *p = h;
    while (head && head->next) {
        if (head->val < head->next->val) {
            p->next = head;
            p = p->next;
            head = head->next;
            continue;
        }
        int flag = 0;
        while (head && head->next && head->val == head->next->val) {
            flag = 1;
            ListNode *temp = head->next;
            head->next = temp->next;
            delete temp;
        }
        if (head->next) {
            ListNode *temp = head->next;
            delete head;
            head = temp;
        }
    }
    if (head) {
        p->next = head;
        p = p->next;
    }
    p->next = nullptr;
    return h->next;
}

int main() {
    return 0;
}
