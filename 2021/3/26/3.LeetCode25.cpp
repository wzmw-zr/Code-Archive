/*************************************************************************
	> File Name: 3.LeetCode25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月26日 星期五 00时24分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *h = new ListNode();
    ListNode *res = h;
    while (head) {
        int n = k;
        ListNode *t = new ListNode();
        ListNode *tail = t;
        int flag = 0;
        while (head && n) {
            ListNode *temp = head->next;
            head->next = t->next;
            t->next = head;
            head = temp;
            if (flag == 0) {
                flag = 1;
                tail = t->next;
            }
            n--;
        }
        if (n == 0) {
            h->next = t->next;
            h = tail;
        } else {
            ListNode *p = new ListNode();
            ListNode *x = t->next;
            while (x) {
                ListNode *temp = x->next;
                x->next = p->next;
                p->next = x;
                x = temp;
            }
            h->next = p->next;
            delete p;
        }
        delete t;
    }
    return res->next;
}

int main() {
    return 0;
}
