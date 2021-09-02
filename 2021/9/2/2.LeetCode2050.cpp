/*************************************************************************
	> File Name: 2.LeetCode2050.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月02日 星期四 14时33分37秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() = default;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode *l = head, *r = head;
    for (int i = 1; i < k; i++) r = r->next;
    while (r->next) r = r->next, l = l->next;
    return l;
}

int main() {
    return 0;
}
