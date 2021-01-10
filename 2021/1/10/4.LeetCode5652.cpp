/*************************************************************************
	> File Name: 4.LeetCode5652.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月10日 星期日 10时34分11秒
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

int get_len(ListNode *head) {
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}

ListNode *get_k_th_pre(ListNode *head, int k) {
    while (k--) head = head->next;
    return head;
}

ListNode* swapNodes(ListNode* head, int k) {
    int len = get_len(head);
    ListNode *temp = new ListNode();
    temp->next = head;
    ListNode *node_1 = get_k_th_pre(temp, k - 1);
    ListNode *node_2 = get_k_th_pre(temp, len - k);
    ListNode *temp_1 = node_1->next;
    ListNode *temp_2 = node_2->next;
    ListNode *next_1 = temp_1->next;
    ListNode *next_2 = temp_2->next;
    node_1->next = temp_2;
    node_2->next = temp_1;
    temp_1->next = next_2;
    temp_2->next = next_1;
    return temp->next;
}

int main() {
    return 0;
}
