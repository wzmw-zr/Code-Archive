/*************************************************************************
	> File Name: 2.LeetCode25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月26日 星期五 00时12分33秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode *head, int k) {
    vector<ListNode *> nodes;
    while (head) {
        nodes.push_back(head);
        head = head->next;
    }
    int n = nodes.size();
    for (int i = 0; i < n - k + 1; i += k) {
        for (int j = i, m = i + k - 1; j < m; j++, m--) swap(nodes[j], nodes[m]);
    }
    for (int i = 0; i < n - 1; i++) nodes[i]->next = nodes[i + 1];
    nodes[n - 1]->next = nullptr;
    return nodes[0];
}

int main() {
    return 0;
}
