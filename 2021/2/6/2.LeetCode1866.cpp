/*************************************************************************
	> File Name: 2.LeetCode1866.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月06日 星期六 15时48分40秒
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

ListNode *detectCycle(ListNode *head) {
    if (!head) return nullptr;
    ListNode *p = head, *q = head;
    int len = 0;
    do {
        p = p->next;
        q = q->next;
        if (!q) return nullptr;
        q = q->next;
        if (!q) return nullptr;
        len++;
    } while (p && q && p != q);
    p = q = head;
    while (len--)  p = p->next;
    while (p != q) p = p->next, q = q->next;
    return p;
}

int main() {
    return 0;
}
