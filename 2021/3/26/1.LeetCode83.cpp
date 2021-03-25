/*************************************************************************
	> File Name: 1.LeetCode83.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月26日 星期五 00时01分57秒
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
    ListNode *ans = head;
    while (head && head->next) {
        if (head->val == head->next->val) {
            ListNode *temp = head->next;
            head->next = temp->next;
            delete temp;
        } else head = head->next;
    }
    return ans;
}

int main() {
    return 0;
}
