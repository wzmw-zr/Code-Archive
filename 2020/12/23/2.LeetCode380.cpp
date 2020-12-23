/*************************************************************************
	> File Name: 2.LeetCode380.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月23日 星期三 09时40分33秒
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
#include<ctime>
using namespace std;

class RandomizedSet {
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
    int cnt;
    unordered_map<int, ListNode *> mp;

    RandomizedSet() : head(new ListNode()), tail(new ListNode()), cnt(0) {
        srand(time(0));
        head->next = tail;
        tail->pre = head;
    }

    bool insert(int val) {
        if (mp.count(val)) return false;
        ListNode *temp = new ListNode(val);
        mp[val] = temp;
        temp->next = head->next;
        temp->pre = head;
        head->next->pre = temp;
        head->next = temp;
        cnt++;
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val)) return false;
        ListNode *temp = mp[val];
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        mp.erase(mp.find(val));
        delete temp;
        cnt--;
        return true;
    }

    int getRandom() {
        int ind = rand() % cnt;
        ListNode *node = head->next;
        while (ind) {
            node = node->next;
            ind--;
        }
        return node->val;
    }
};

int main() {
    return 0;
}
