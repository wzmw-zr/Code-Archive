/*************************************************************************
	> File Name: 1.LeetCode61.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月27日 星期六 00时01分32秒
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
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int get_len(ListNode *head) {
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}

ListNode* rotateRight(ListNode* head, int k) {
    int n = get_len(head);
    if (k == 0 || n == 0) return head;
    k %= n;
    if (k == 0) return head;
    ListNode *h = new ListNode(0, head);
    ListNode *t = h;
    for (int i = 0; i < n - k; i++) t = t->next;
    h->next = t->next;
    ListNode *temp = t->next;
    while (temp && temp->next) temp = temp->next;
    temp->next = head;
    t->next = nullptr;
    ListNode *ans = h->next;
    delete h;
    return ans;
}

int main() {
    return 0;
}
