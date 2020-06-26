/*************************************************************************
	> File Name: 1.LeetCode1591.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月26日 星期五 06时55分24秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeDuplicateNodes(ListNode* head) {
    unordered_map<int, int> mp;
    ListNode node(0), *p = &node;
    node.next = head;
    while (p->next) {
        if (mp.find(p->next->val) == mp.end()) {
            mp[p->next->val] = 1;
            p = p->next;
        } else {
            ListNode *tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        }
    }
    return node.next;
}

int main() {
    int n;
    cin >> n;
    ListNode *head, *p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ListNode *tmp = new ListNode(x);
        if (i == 0) head = tmp, p = head;
        else {
            p->next = tmp, p = p->next;
        }
    }
    head = removeDuplicateNodes(head);
    p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
