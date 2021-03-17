/*************************************************************************
	> File Name: 2.LeetCode92.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月18日 星期四 00时10分49秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *p = new ListNode();
    p->next = head;
    ListNode *ptr = p;
    for (int i = 1; i < left; i++) ptr = ptr->next;
    ListNode *t = new ListNode();
    ListNode *mid = ptr->next;
    for (int i = left; i <= right; i++) {
        ListNode *temp = mid->next;
        mid->next = t->next;
        t->next = mid;
        mid = temp;
    }
    ptr->next->next = mid;
    ptr->next = t->next;
    ListNode *ans = p->next;
    delete p;
    delete t;
    return ans;
}

int main() {
    return 0;
}
