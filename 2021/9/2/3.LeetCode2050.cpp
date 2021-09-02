/*************************************************************************
	> File Name: 3.LeetCode2050.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月02日 星期四 14时37分39秒
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
    queue<ListNode *> que;
    while (head) {
        if (que.size() == k) que.pop();
        que.push(head);
        head = head->next;
    }
    return que.front();
}

int main() {
    return 0;
}
