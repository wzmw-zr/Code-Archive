/*************************************************************************
	> File Name: 7.LeetCode369.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月15日 星期一 23时20分50秒
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
};

ListNode *reverse_list(ListNode *head) {
    ListNode *h = new ListNode();
    while (head) {
        ListNode *temp = head->next;
        head->next = h->next;
        h->next = head;
        head = temp;
    }
    ListNode *ans = h->next;
    delete h;
    return ans;
}

void smooth(ListNode *head) {
    while (head->next && head->val >= 10) {
        head->next->val++;
        head->val -= 10;
        head = head->next;
    }
    if (head->val < 10) return ;
    head->next = new ListNode(1);
    head->val -= 10;
    return ;
}

void show_list(ListNode *head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

ListNode* plusOne(ListNode* head) {
    show_list(head);
    head = reverse_list(head);
    show_list(head);
    head->val++;
    smooth(head);
    return reverse_list(head);
}

int main() {
    return 0;
}
