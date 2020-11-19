/*************************************************************************
	> File Name: 1.LeetCode147.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月20日 星期五 00时05分41秒
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

ListNode* insertionSortList(ListNode* head) {
    if (!head) return NULL;
    ListNode *node = new ListNode(INT32_MIN);
    while (head) {
        ListNode *temp = node;
        ListNode *head_t = head;
        head = head->next;
        while (!temp && !temp->next) {
            if (temp->val <= head_t->val && head_t->val <= temp->next->val) {
                head_t->next = temp->next;
                temp->next = head_t;
                break;
            }
            temp = temp->next;
        }
        if (!temp->next) {
            temp->next = head_t;
            head_t->next = nullptr;
        }
    }
    return node->next;
}

int main() {
    return 0;
}
