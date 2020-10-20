/*************************************************************************
    > File Name: 1.LeetCode143.cpp
    > Author:赵睿 
    > Mail: 1767153298@qq.com
    > Created Time: 2020年10月20日 星期二 08时09分21秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

void output(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void reorderList(ListNode* head) {
    if (!head) return ;
    vector<ListNode *> nodes, ch_nodes;
    ListNode *temp = head;
    while (temp) {
        nodes.push_back(temp);
        temp = temp->next;
    }
    int i = 0, j = nodes.size() - 1;
    for ( ; i < j; i++, j--) {
        ch_nodes.push_back(nodes[i]);
        ch_nodes.push_back(nodes[j]);
    }
    if (i == j) ch_nodes.push_back(nodes[i]);
    for (i = 0; i < nodes.size() - 1; i++) ch_nodes[i]->next = ch_nodes[i + 1];
    ch_nodes[i]->next = nullptr;
}


int main() {
    int num;
    ListNode *head = nullptr;
    vector<int> nums;
    while (cin >> num) nums.push_back(num);
    for (int i = nums.size() - 1; i >= 0; i--) {
        ListNode *temp = new ListNode(nums[i]);
        temp->next = head;
        head = temp;
    }
    output(head);
    reorderList(head);
    output(head);
    return 0;
}
