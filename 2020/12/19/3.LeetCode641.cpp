/*************************************************************************
	> File Name: 3.LeetCode641.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月19日 星期六 16时34分24秒
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

class MyCircularDeque {
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

    MyCircularDeque(int k) : cnt(k), head(new ListNode()), tail(new ListNode()) {
        head->next = tail;
        tail->pre = head;
    }

    bool insertFront(int value) {
        if (!cnt) return false;
        ListNode *temp = new ListNode(value);
        temp->next = head->next;
        temp->pre = head;
        head->next->pre = temp;
        head->next = temp;
        cnt--;
        return true;
    }

    bool insertLast(int value) {
        if (!cnt) return false;
        ListNode *temp = new ListNode(value);
        temp->next = tail;
        temp->pre = tail->pre;
        tail->pre->next = temp;
        tail->pre = temp;
        cnt--;
        return true;
    }

    bool deleteFront() {
        if (head->next == tail) return false;
        ListNode *temp = head->next;
        head->next = temp->next;
        temp->next->pre = head;
        cnt++;
        delete temp;
        return true;
    }

    bool deleteLast() {
        if (head->next == tail) return false;
        ListNode *temp = tail->pre;
        temp->pre->next = tail;
        tail->pre = temp->pre;
        cnt++;
        delete temp;
        return true;
    }

    int getFront() {
        if (head->next == tail) return -1;
        return head->next->val;
    }

    int getRear() {
        if (head->next == tail) return -1;
        return tail->pre->val;
    }

    bool isEmpty() {
        return head->next == tail;
    }

    bool isFull() {
        return cnt == 0;
    }
};

int main() {
    return 0;
}
