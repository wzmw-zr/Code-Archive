/*************************************************************************
	> File Name: 2.LeetCode1670.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月19日 星期六 08时31分21秒
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

class FrontMiddleBackQueue {
public:
    struct ListNode {
        int val;
        ListNode *pre;
        ListNode *next;
        ListNode() : pre(nullptr), next(nullptr) {}
        ListNode(int val) : val(val), pre(nullptr), next(nullptr) {}
    };

    ListNode *head;
    ListNode *tail;
    ListNode *middle;
    int cnt;

    FrontMiddleBackQueue() : cnt(0) {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->pre = head;
        middle = head;
    }

    void pushFront(int val) {
        ListNode *temp = new ListNode(val);
        temp->next = head->next;
        temp->pre = head->next->pre;
        head->next->pre = temp;
        head->next = temp;
        if (cnt == 0) middle = temp;
        if (cnt & 1) middle = middle->pre; 
        cnt++;
    }

    void pushMiddle(int val) {
        ListNode *temp = new ListNode(val);
        if (cnt & 1) {
            temp->next = middle;
            temp->pre = middle->pre;
            middle->pre->next = temp;
            middle->pre = temp; 
        } else {
            temp->next = middle->next;
            temp->pre = middle;
            middle->next->pre = temp;
            middle->next = temp;
        }
        middle = temp;
        cnt++;
    }

    void pushBack(int val) {
        ListNode *temp = new ListNode(val);
        temp->next = tail;
        temp->pre = tail->pre;
        tail->pre->next = temp;
        tail->pre = temp;
        if (!(cnt & 1)) middle = middle->next;
        cnt++;
    }

    int popFront() {
        if (!cnt) return -1;
        ListNode *temp = head->next;
        temp->next->pre = head;
        head->next = temp->next;
        if (!(cnt & 1)) middle = middle->next;
        if (cnt == 1) middle = head;
        int ans = temp->val;
        cnt--;
        delete temp;
        return ans;
    }

    int popMiddle() {
        if (!cnt) return -1;
        ListNode *temp = middle;
        middle->pre->next = middle->next;
        middle->next->pre = middle->pre;
        if (cnt & 1) middle = middle->pre;
        else middle = middle->next;
        int ans = temp->val;
        cnt--;
        delete temp;
        return ans;
    }

    int popBack() {
        if (!cnt) return -1;
        ListNode *temp = tail->pre;
        tail->pre = temp->pre;
        temp->pre->next = tail;
        if (cnt & 1) middle = middle->pre;
        int ans = temp->val;
        cnt--;
        delete temp;
        return ans;
    }
};

int main() {
    return 0;
}
