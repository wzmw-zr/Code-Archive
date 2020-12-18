/*************************************************************************
	> File Name: 3.LeetCode460.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月18日 星期五 17时58分57秒
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
        ListNode() : pre(nullptr), next(nullptr) {}
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

    int capacity;
    CntNode *head;
    CntNode *tail;
    unordered_map<int, CntNode *> cnt_mp;
    unordered_map<int, ListNode *> kw_mp;

    LFUCache(int capacity) : capacity(capacity), head(new CntNode(0)), tail(new CntNode(INT32_MAX)) {
        cnt_mp[0] = head;
        cnt_mp[INT32_MAX] = tail;
        head->next = tail;
        tail->pre = head;
    }

    void remove_from_cnt_list(ListNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void add_to_cnt_list(ListNode *node) {
        int cnt = node->cnt;
        if (!cnt_mp.count(cnt)) {
            cnt_mp[cnt] = new CntNode(cnt);   
            CntNode *temp = cnt_mp[cnt - 1];
            cnt_mp[cnt]->next = tail;
            cnt_mp[cnt]->pre = tail->pre;
            tail->pre->next = cnt_mp[cnt];
            tail->pre = cnt_mp[cnt];
        }
        CntNode *temp = cnt_mp[cnt];
        node->pre = temp->tail->pre;
        node->next = temp->tail;
        temp->tail->pre->next = node;
        temp->tail->pre = node;
    }

    int get(int key) {
        if (!kw_mp.count(key)) return -1;
        ListNode *temp = kw_mp[key];
        remove_from_cnt_list(temp);
        temp->cnt++;
        add_to_cnt_list(temp);
        return temp->value;
    }

    ListNode *get_to_erase_node() {
        CntNode *node = head->next;
        while (node != tail) {
            if (node->head->next == node->tail) node = node->next;
            return node->head->next;
        }
        return nullptr;
    }

    void put(int key, int value) {
        if (kw_mp.count(key)) {
            ListNode *temp = kw_mp[key];
            temp->value = value;
            remove_from_cnt_list(temp);
            temp->cnt++;
            add_to_cnt_list(temp);
        } else {
            if (capacity) {
                ListNode *temp = new ListNode(key, value);
                kw_mp[key] = temp;
                add_to_cnt_list(temp);
                capacity--;
            } else {
                ListNode *temp = new ListNode(key, value);
                ListNode *to_erase_node = get_to_erase_node();
                if (!to_erase_node) return ;
                kw_mp.erase(kw_mp.find(to_erase_node->key));
                remove_from_cnt_list(to_erase_node);
                kw_mp[key] = temp;
                add_to_cnt_list(temp);
                delete to_erase_node;
            }
        }
    }
};

int main() {
    return 0;
}
