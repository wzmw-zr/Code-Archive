/*************************************************************************
	> File Name: 5.LeetCode146.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月16日 星期三 19时02分33秒
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

class LRUCache {
public:
    struct ListNode {
        int key;
        int value;
        ListNode *pre;
        ListNode *next;
        ListNode() : pre(nullptr), next(nullptr) {}
        ListNode(int key, int value) : key(key), value(value), pre(nullptr), next(nullptr) {}
    };

    ListNode *__head, *__tail;
    unordered_map<int, ListNode *> mp;
    int rest;

    LRUCache(int capacity) : __head(new ListNode()), __tail(new ListNode()), rest(capacity) {
        __head->next = __tail;
        __tail->pre = __head;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        ListNode *temp = mp[key];
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        temp->pre = __head;
        temp->next = __head->next;
        __head->next->pre = temp;
        __head->next = temp;
        return temp->value;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            ListNode *temp = mp[key];
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            temp->pre = __head;
            temp->next = __head->next;
            __head->next->pre = temp;
            __head->next = temp;
            temp->value = value;
        } else {
            if (rest) {
                ListNode *temp = new ListNode(key, value);
                mp[key] = temp;
                temp->pre = __head;
                temp->next = __head->next;
                __head->next->pre = temp;
                __head->next = temp;
                rest--;
            } else {
                ListNode *temp = __tail->pre;
                temp->pre->next = __tail;
                __tail->pre = temp->pre;
                mp.erase(mp.find(temp->key));
                temp->key = key;
                temp->value = value;
                mp[key] = temp;
                temp->next = __head->next;
                temp->pre = __head;
                __head->next->pre = temp;
                __head->next = temp;
            }
        }
    }
};

int main() {
    return 0;
}
