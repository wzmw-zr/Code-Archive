/*************************************************************************
	> File Name: 1.LeetCode23.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月26日 星期日 07时12分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<ctime>
#include<unistd.h>
using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode; 

ListNode *GetNewNode(int x) {
    ListNode *node = (ListNode *) calloc(sizeof(ListNode), 1);
    node->val = x;
    return node;
}

void output(ListNode *head) {
    ListNode *temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *mergeKLists(vector<ListNode*> &lists) {
    ListNode *head = NULL;
    if (lists.size() == 0) {
        return head;
    }
    if (lists.size() == 1) {
        return lists[0];
    }
    for (int i = 0; i < lists.size() - 1; i++) {
        int cnt = 0;
        ListNode *t_head = NULL;
        ListNode *temp = NULL;
        ListNode *head1 = lists[i], *head2 = lists[i + 1]; 
        while (head1 || head2) {
            if (head1 && (!head2 || head1->val < head2->val)) {
                if (cnt == 0) {
                    t_head = head1;
                    temp = t_head;
                    head1 = head1->next;
                    cnt++;
                    continue;
                }
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
                cnt++;
            } else {
                if (cnt == 0) {
                    t_head = head2;
                    temp = t_head;
                    head2 = head2->next;
                    cnt++;
                    continue;
                }
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
                cnt++;
            }
        }
        lists[i + 1] = t_head;
    }
    return lists[lists.size() - 1];
}


int main() {
    int n;
    cin >> n;
    vector<ListNode *> data;
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        ListNode *head = NULL, *temp = NULL;
        for (int i = 0; i < cnt; i++) {
            int num;
            cin >> num;
            if (i == 0) {
                head = GetNewNode(num);
                temp = head;
                continue;
            }
            temp->next = GetNewNode(num);
            temp = temp->next;
        }
        data.push_back(head);
    }
    ListNode *res = mergeKLists(data);
    output(res);
    return 0;
}
