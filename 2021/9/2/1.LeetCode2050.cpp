/*************************************************************************
	> File Name: 1.LeetCode2050.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月02日 星期四 14时26分16秒
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
    int l = 0;
    ListNode *temp = head;
    while (temp) {
        l++;
        temp = temp->next;
    }
    int ind = max(1, l - k + 1);
    for (int i = 1; i < ind; i++) head = head->next;
    return head;
}

int main() {
    return 0;
}
