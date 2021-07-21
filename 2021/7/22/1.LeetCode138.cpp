/*************************************************************************
	> File Name: 1.LeetCode138.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月22日 星期四 00时04分00秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    unordered_map<Node *, Node *> mp;
    Node *p = head;
    mp[NULL] = NULL;
    while (p) {
        mp[p] = new Node(p->val);
        p = p->next;
    }
    p = head;
    while (p) {
        mp[p]->next = mp[p->next];
        mp[p]->random = mp[p->random];
        p = p->next;
    }
    return mp[head];
}

int main() {
    return 0;
}
