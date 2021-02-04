/*************************************************************************
	> File Name: 2.LeetCode1858.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月05日 星期五 00时13分42秒
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
    ListNode() = default;
    ListNode(int val) : val(val), next(nullptr) {}
};

int kthToLast(ListNode* head, int k) {
    ListNode *p = head, *q = head;
    while (k--) p = p->next;
    while (p) p = p->next, q = q->next;
    return q->val;
}

int main() {
    return 0;
}
