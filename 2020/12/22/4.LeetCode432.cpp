/*************************************************************************
	> File Name: 4.LeetCode432.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月22日 星期二 18时53分00秒
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

class AllOne {
public:
    struct ListNode {
        string key;
        int value;
        ListNode *pre;
        ListNode *next;
        ListNode() : pre(nullptr), next(nullptr) {}
        ListNode(string key) : key(key), value(0), pre(nullptr), next(nullptr) {}
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
    unordered_map<string, ListNode *> key_mp;
    int node_cnt;

    AllOne() : head(new CntNode(0)), tail(new CntNode(INT32_MAX)), node_cnt(0) {
        head->next = tail;
        tail->pre = head;
    }

    void delete_ListNode(ListNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void insert_to_node_list(CntNode *cnt, ListNode *node) {
        node->next = cnt->head->next;
        node->pre = cnt->head;
        cnt->head->next->pre = node;
        cnt->head->next = node;
    }

    void insert_to_cnt_list(CntNode *node) {
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
    }

    void inc(string key) {
        if (!key_mp.count(key)) {
            key_mp[key] = new ListNode(key);   
            node_cnt++;
        }
        else delete_ListNode(key_mp[key]);
        int cnt = ++key_mp[key]->value;
        if (!cnt_mp.count(cnt)) {
            cnt_mp[cnt] = new CntNode(cnt);
            insert_to_cnt_list(cnt_mp[cnt]);
        }
        insert_to_node_list(cnt_mp[cnt], key_mp[key]);
    }

    void dec(string key) {
        if (!key_mp.count(key)) return ;
        ListNode *temp = key_mp[key];
        if (!(--temp->value)) {
            delete_ListNode(temp);
            key_mp.erase(key_mp.find(temp->key));
            delete temp;
            node_cnt--;
        } else {
            delete_ListNode(temp);
            int cnt = temp->value;
            insert_to_node_list(cnt_mp[cnt], temp);
        }
    }

    string getMaxKey() {
        if (!node_cnt) return "";
        CntNode *node = tail->pre;
        while (node != head && node->head->next == node->tail) node = node->pre;
        return node->head->next->key;
    }

    string getMinKey() {
        if (!node_cnt) return "";
        CntNode *node = head->next;
        while (node != tail && node->head->next == node->tail) node = node->next;
        return node->head->next->key;
    }
};

int main() {
    return 0;
}
