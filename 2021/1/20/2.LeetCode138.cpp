/*************************************************************************
	> File Name: 2.LeetCode138.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月20日 星期三 00时16分29秒
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

struct Node {
    int val;
    Node *next;
    Node *random;

    Node() = default;
    Node(int val) : val(val), next(NULL), random(NULL) {}
};

Node* copyRandomList(Node* head) {
    unordered_map<Node *, Node *> mp;
    mp[NULL] = NULL;
    Node *temp = head;
    while (temp) {
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp) {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}

int main() {
    return 0;
}
