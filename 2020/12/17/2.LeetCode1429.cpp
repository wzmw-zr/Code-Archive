/*************************************************************************
	> File Name: 2.LeetCode1429.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月17日 星期四 09时22分21秒
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

class FirstUnique {
public:
    struct ListNode {
        int val;
        ListNode *pre;
        ListNode *next;
        ListNode() : pre(nullptr), next(nullptr) {}
        ListNode(int val) : val(val), pre(nullptr), next(nullptr) {}
    };

    ListNode *head, *tail;
    unordered_map<int, ListNode *> mp;
    unordered_map<int, int> cnt;

    FirstUnique(vector<int>& nums) : head(new ListNode()), tail(new ListNode()) {
        head->next = tail;
        tail->pre = head;
        for (int x : nums) add(x);
    }

    int showFirstUnique() {
        if (head->next == tail) return -1;
        return head->next->val;
    }

    void add(int value) {
        if (cnt.count(value)) {
            if (cnt[value] >= 2) {
                cnt[value]++;
                return ;
            }
            ListNode *temp = mp[value];
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            mp.erase(mp.find(value));
            delete temp;
            cnt[value]++;
        } else {
            cnt[value]++;
            mp[value] = new ListNode(value);
            mp[value]->next = tail;
            mp[value]->pre = tail->pre;
            tail->pre->next = mp[value];
            tail->pre = mp[value];
        }
    }
};

int main() {
    return 0;
}
