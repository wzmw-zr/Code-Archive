/*************************************************************************
	> File Name: 3.LeetCode5927.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月14日 星期日 10时35分08秒
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

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(0), next(nullptr) {}
};

int get_len(ListNode *head) {
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}

ListNode *reverse_list(ListNode *head) {
    vector<ListNode *> nodes;
    while (head) {
        nodes.push_back(head);
        head = head->next;
    }
    reverse(nodes.begin(), nodes.end());
    int n = nodes.size();
    for (int i = 0; i < n - 1; i++) nodes[i]->next = nodes[i + 1];
    nodes[n - 1]->next = nullptr;
    return nodes[0];
}

ListNode* reverseEvenLengthGroups(ListNode* head) {
    int wzmw_zr_q2 = 0;
    int n = get_len(head);
    vector<ListNode *> nodes;
    ListNode *h = head;
    for (int i = 1, l = 1; i <= n; i += min(l, n - i + 1), l++) {
        nodes.push_back(h);
        ListNode *temp = h;
        for (int j = 0; j < min(l - 1, n - i); j++) temp = temp->next;
        h = temp->next;
        temp->next = nullptr;
    }
    for (auto &&node : nodes) {
        if (get_len(node) & 1) continue;
        node = reverse_list(node);
    }
    ListNode *ans = new ListNode();
    ListNode *temp = ans;
    for (auto node : nodes) {
        temp->next = node;
        while (temp && temp->next) temp = temp->next;
    }
    temp = ans;
    ans = ans->next;
    delete temp;
    return ans;
}

int main() {
    return 0;
}
