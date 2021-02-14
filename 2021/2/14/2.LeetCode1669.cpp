/*************************************************************************
	> File Name: 2.LeetCode1669.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月14日 星期日 22时52分20秒
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode *get_kth_node_pre(ListNode *head, int k) {
    while (k > 1) head = head->next, k--;
    return head;
}

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *head = new ListNode();
    ListNode *tail = list2;
    head->next = list1;
    ListNode *p = get_kth_node_pre(head, a);
    ListNode *q = get_kth_node_pre(head, b);
    while (tail->next) tail = tail->next;
    tail->next = q->next->next;
    q->next->next = nullptr;
    ListNode *t = p->next;
    while (t) {
        ListNode *temp = t->next;
        delete t;
        t = temp;
    }
    p->next = list2;
    return head->next;
}

int main() {
    return 0;
}
