/*************************************************************************
	> File Name: 3.LeetCode460.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月17日 星期四 10时38分37秒
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

class LFUCache {
public:
    struct ListNode {
        int key;
        int value;
        int cnt;
        ListNode *pre;
        ListNode *next;
        ListNode() : cnt(1), pre(nullptr), next(nullptr) {}
        ListNode(int key, int value) : key(key), value(value), cnt(1), pre(nullptr), next(nullptr) {}
    };

    struct CntNode {
        int cnt;
        ListNode *head;
        ListNode *tail;
        CntNode *pre;
        CntNode *next;
        CntNode() : head(new ListNode()), tail(new ListNode()), pre(nullptr), next(nullptr) {
            head->next = tail;
            tail->pre = head;
        }
        CntNode(int cnt) : cnt(cnt), head(new ListNode()), tail(new ListNode()), pre(nullptr), next(nullptr) {
            head->next = tail;
            tail->pre = head;
        }
    };

    CntNode *head;
    CntNode *tail;

    unordered_map<int, CntNode *> cnt_mp;
    unordered_map<int, ListNode *> kw_mp;
    int rest;

    LFUCache(int capacity) : rest(capacity), head(new CntNode()), tail(new CntNode()) {
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!kw_mp.count(key)) return -1;
        ListNode *temp = kw_mp[key];
        int cnt = ++temp->cnt;
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        if (cnt_mp.count(cnt)) {
            temp->next = cnt_mp[cnt]->tail;
            temp->pre = cnt_mp[cnt]->tail->pre;
            cnt_mp[cnt]->tail->pre->next = temp;
            cnt_mp[cnt]->tail->pre = temp;
        } else {
            CntNode *cnt_node_pre = cnt_mp[cnt - 1];
            CntNode *new_cnt_node = new CntNode(cnt);
            new_cnt_node->pre = cnt_node_pre;
            new_cnt_node->next = cnt_node_pre->next;
            cnt_node_pre->next->pre = new_cnt_node;
            cnt_node_pre->next = new_cnt_node;
            temp->next = new_cnt_node->tail;
            temp->pre = new_cnt_node->tail->pre;
            new_cnt_node->tail->pre->next = temp;
            new_cnt_node->tail->pre = temp;
        }
        if (cnt_mp[cnt - 1]->head->next == cnt_mp[cnt - 1]->tail) {
            delete cnt_mp[cnt - 1];
            cnt_mp.erase(cnt_mp.find(cnt - 1));
        }
        return temp->value;
    }

    void put(int key, int value) {
        if (kw_mp.count(key)) {
            ListNode *temp = kw_mp[key];
            temp->value = value;
            int cnt = ++temp->cnt;
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            if (cnt_mp.count(cnt)) {
                temp->next = cnt_mp[cnt]->tail;
                temp->pre = cnt_mp[cnt]->tail->pre;
                cnt_mp[cnt]->tail->pre->next = temp;
                cnt_mp[cnt]->tail->pre = temp;
            } else {
                CntNode *cnt_node_pre = cnt_mp[cnt - 1];
                CntNode *new_cnt_node = new CntNode(cnt);
                new_cnt_node->pre = cnt_node_pre;
                new_cnt_node->next = cnt_node_pre->next;
                cnt_node_pre->next->pre = new_cnt_node;
                cnt_node_pre->next = new_cnt_node;
                temp->next = new_cnt_node->tail;
                temp->pre = new_cnt_node->tail->pre;
                new_cnt_node->tail->pre->next = temp;
                new_cnt_node->tail->pre = temp;
            }
            if (cnt_mp[cnt - 1]->head->next == cnt_mp[cnt - 1]->tail) {
                delete cnt_mp[cnt - 1];
                cnt_mp.erase(cnt_mp.find(cnt - 1));
            }
        } else {
            if (rest) {
                ListNode *temp = new ListNode(key, value);
                kw_mp[key] = temp;
                if (!cnt_mp.count(1)) cnt_mp[1] = new CntNode(1);
                CntNode *cnt_node = cnt_mp[1];
                temp->next = cnt_node->tail;
                temp->pre = cnt_node->tail->pre;
                cnt_node->tail->pre->next = temp;
                cnt_node->tail->pre = temp;
                rest--;
            } else {
                ListNode *temp = head->head->next;
                kw_mp.erase(kw_mp.find(temp->key));
                kw_mp[key] = temp;
                temp->next->pre = temp->next;
                temp->pre->next = temp->next;
                temp->key = key;
                temp->value = value;
                int cnt = temp->cnt;
                temp->cnt = 1;
                if (!cnt_mp.count(1)) cnt_mp[1] = new CntNode(1);
                CntNode *cnt_node = cnt_mp[1];
                temp->next = cnt_node->tail;
                temp->pre = cnt_node->tail->pre;
                cnt_node->tail->pre->next = temp;
                cnt_node->tail->pre = temp;
                if (cnt_mp[cnt]->head->next == cnt_mp[cnt]->tail) {
                    delete cnt_mp[cnt];
                    cnt_mp.erase(cnt_mp.find(cnt));
                }
            }
        }
    }
};

int main() {
    return 0;
}
