/*************************************************************************
	> File Name: 1.LeetCode92.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月18日 星期四 00时02分07秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    vector<ListNode *> nodes;
    while (head) {
        nodes.push_back(head);
        head = head->next;
    }
    int n = nodes.size();
    while (left < right) {
        swap(nodes[left - 1], nodes[right - 1]);
        left++, right--;
    }
    for (int i = 0; i < n - 1; i++) nodes[i]->next = nodes[i + 1];
    nodes[n - 1]->next = nullptr;
    return nodes[0];
}

int main() {
    return 0;
}
