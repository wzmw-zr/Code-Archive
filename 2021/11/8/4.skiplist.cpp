/*************************************************************************
	> File Name: 4.skiplist.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月08日 星期一 18时09分09秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include<unordered_set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_H 32

struct Node {
    int val;
    int len;
    vector<Node *> next;

    Node(int val, int len) : val(val), len(len), next(vector<Node *>(len, nullptr)) {}
};

struct SkipList {
    Node *head;

    SkipList() : head(new Node(INT32_MIN, MAX_H)) {};

    int get_height() {
        int h = 1;
        while (h < MAX_H) {
            if (rand() & 1) h++;
            else break;
        }
        return h;
    }

    void insert(int val) {
        Node *p = head;
        vector<Node *> pre(32);
        for (int i = 31; i >= 0; i--) {
            while (p->next[i] && p->next[i]->val < val) p = p->next[i];
            pre[i] = p;
        }
        int h = get_height();
        Node *temp = new Node(val, h);
        for (int i = 0; i < h; i++) {
            temp->next[i] = pre[i]->next[i];
            pre[i]->next[i] = temp;
        }
    }

    bool search(int val) {
        Node *p = head;
        vector<Node *> pre(32);
        for (int i = 31; i >= 0; i--) {
            while (p->next[i] && p->next[i]->val < val) p = p->next[i];
            pre[i] = p;
        }
        return p->next[0] ? (p->next[0]->val == val ? true : false) : false;
    }

    void erase(int val) {
        Node *p = head;
        vector<Node *> pre(32);
        for (int i = 31; i >= 0; i--) {
            while (p->next[i] && p->next[i]->val < val) p = p->next[i];
            pre[i] = p;
        }
        if (!p->next[0] || p->next[0]->val != val) return ;
        p = p->next[0];
        for (int i = 0; i < p->len; i++) pre[i]->next[i] = p->next[i];
        delete p;
    }

    void print() {
        Node *p = head->next[0];
        while (p) {
            cout << p->val << " ";
            p = p->next[0];
        }
        cout << endl;
    }
};

int main() {
    srand(time(0));
    int t, n;
    SkipList list;
    while (cin >> t >> n) {
        if (t == 0) {
            list.insert(n);
            list.print();
        } else if (t == 1) {
            cout << "Search " << n << endl;
            cout << (list.search(n) ? "Find" : "Not Find") << endl;
        } else {
            list.erase(n);
            list.print();
        }
    }
    return 0;
}
