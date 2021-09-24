/*************************************************************************
	> File Name: 1.LeetCode430.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月24日 星期五 08时52分36秒
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
    Node *prev;
    Node *child;

    Node() = default;
    Node(int val) : val(val), prev(nullptr), next(nullptr), child(nullptr) {}
};

Node *dfs(Node *head) {
    if (!head) return nullptr;
    Node *temp = head;
    while (temp) {
        if (temp->child) {
            Node *p = dfs(temp->child);
            p->next = temp->next;
            if (temp->next) temp->next->prev = p;
            temp->next = temp->child;
            temp->child = nullptr;
            temp->next->prev = temp;
            temp = p;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp && temp->next) temp = temp->next;
    return temp;
}

Node* flatten(Node* head) {
    Node *temp = head;
    while (temp) {
        if (temp->child) {
            Node *p = dfs(temp->child);
            p->next = temp->next;
            if (temp->next) temp->next->prev = p;
            temp->next = temp->child;
            temp->child = nullptr;
            temp->next->prev = temp;
            temp = p;
        } 
        temp = temp->next;
    }
    return head;
}

int main() {
    return 0;
}
