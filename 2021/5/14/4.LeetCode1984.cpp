/*************************************************************************
	> File Name: 4.LeetCode1984.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月14日 星期五 01时29分30秒
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
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    while (l1 || l2) {
        ListNode *temp = new ListNode(0);
        if (l1) {
            temp->val += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            temp->val += l2->val;
            l2 = l2->next;
        }
        tail->next = temp;
        tail = tail->next;
    }
    ListNode *temp = head->next;
    while (temp) {
        if (temp->val < 10) {
            temp = temp->next;
            continue;
        }
        if (!temp->next) temp->next = new ListNode(0);
        temp->next->val += temp->val / 10;
        temp->val %= 10;
        temp = temp->next;
    }
    ListNode *ans = head->next;
    delete head;
    return ans;
}

int main() {
    return 0;
}
