/*************************************************************************
	> File Name: 5.LeetCode5652.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月10日 星期日 10时51分00秒
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

ListNode* swapNodes(ListNode* head, int k) {
    vector<ListNode *> nodes;
    while (head) {
        nodes.push_back(head);
        head = head->next;
    }
    int n = nodes.size();
    if (2 * k == (n + 1)) return nodes[0];
    swap(nodes[k - 1], nodes[n - k]);
    if (k == 1 || k == n) {
        nodes[0]->next = nodes[1];
        nodes[n - 2]->next = nodes[n - 1];
        nodes[n - 1]->next = nullptr;
    } else {
        nodes[k - 2]->next = nodes[k - 1];
        nodes[k - 1]->next = nodes[k];
        nodes[n - k - 1]->next = nodes[n - k];
        nodes[n - k]->next = nodes[n - k + 1];
    }
    return nodes[0];
}

int main() {
    return 0;
}

