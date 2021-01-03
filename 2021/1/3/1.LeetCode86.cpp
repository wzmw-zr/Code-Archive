/*************************************************************************
	> File Name: 1.LeetCode86.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月03日 星期日 08时28分08秒
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

void reverse_list(ListNode *head) {
    ListNode *h_1 = new ListNode();
    ListNode *temp = head;
    while (temp) {
        ListNode *t = temp;
        temp = temp->next;
        t->next = h_1->next;
        h_1->next = t;
    }
    head->next = h_1->next;
    delete h_1;
}

ListNode* partition(ListNode* head, int x) {
    ListNode *h_1 = new ListNode(), *h_2 = new ListNode();
    while (head) {
        ListNode *temp = head;
        head = head->next;
        if (temp->val < x) {
            temp->next = h_1->next;
            h_1->next = temp;
        } else {
            temp->next = h_2->next;
            h_2->next = temp;
        }
    }
    reverse_list(h_1);
    reverse_list(h_2);
    ListNode *last = h_1->next;
    if (!last) return h_2->next;
    while (last->next) last = last->next;
    last->next = h_2->next;
    ListNode *ans = h_1->next;
    delete h_1;
    delete h_2;
    return ans;
}

int main() {
    return 0;
}
