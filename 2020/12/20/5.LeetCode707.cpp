/*************************************************************************
	> File Name: 5.LeetCode707.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月20日 星期日 18时35分53秒
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

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *pre;
        ListNode *next;
        ListNode() : pre(nullptr), next(nullptr) {}
        ListNode(int val) : val(val), pre(nullptr), next(nullptr) {}
    };

    int cnt;
    ListNode *head;
    ListNode *tail;

    MyLinkedList() : cnt(0), head(new ListNode()), tail(new ListNode()) {
        head->next = tail;
        tail->pre = head;
    }

    int get(int index) {
        if (index < 0 || index >= cnt) return -1;
        ListNode *temp = head->next;
        int ind = 0;
        while (ind < index) {
            temp = temp->next;   
            ind++;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        ListNode *temp = new ListNode(val);
        temp->next = head->next;
        temp->pre = head;
        head->next->pre = temp;
        head->next = temp;
        cnt++;
    }

    void addAtTail(int val) {
        ListNode *temp = new ListNode(val);
        temp->next = tail;
        temp->pre = tail->pre;
        tail->pre->next = temp;
        tail->pre = temp;
        cnt++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0) {
            addAtHead(val);
            return ;
        }
        if (index == cnt) {
            addAtTail(val);
            return ;
        }
        if (index > cnt) return ;
        ListNode *temp = head;
        int ind = 0;
        while (ind < index) {
            temp = temp->next;
            ind++;
        }
        ListNode *target = new ListNode(val);
        target->next = temp->next;
        target->pre = temp;
        temp->next->pre = target;
        temp->next = target;
        cnt++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) return ;
        ListNode *temp = head->next;
        int ind = 0;
        while (ind < index) {
            temp = temp->next;
            ind++;
        }
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        delete temp;
        cnt--;
    }
};

int main() {
    return 0;
}
