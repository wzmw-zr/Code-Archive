/*************************************************************************
	> File Name: 2.LeetCode1206.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月07日 星期二 21时58分22秒
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
    vector<Node *> next;

    Node() = default;
    Node(int val, int level) : val(val), next(level, nullptr) {}
};

class Skiplist {
public:
    Node *head;

    Skiplist() : head(new Node(INT32_MIN, 32)) {
        srand(time(0));
    }

    bool search(int target) {
        Node *p = head;
        for (int i = 31; i >= 0; i--) {
            while (p->next[i] != nullptr && p->next[i]->val < target) p = p->next[i];
        }
        return p->next[0] == nullptr ? false : p->next[0]->val == target;
    }

    int generate_level() {
        int level = 1;
        while ((rand() & 1) && (level < 32)) level++;
        return level;
    }

    void add(int num) {
        Node *p = head;
        vector<Node *> update(32, nullptr);
        for (int i = 31; i >= 0; i--) {
            while (p->next[i] != nullptr && p->next[i]->val < num) p = p->next[i];
            update[i] = p;
        }
        int level = generate_level();
        Node *node = new Node(num, level);
        for (int i = 0; i < level; i++) {
            node->next[i] = update[i]->next[i];
            update[i]->next[i] = node;
        }
    }

    bool erase(int num) {
        Node *p = head;
        vector<Node *> update(32, nullptr);
        for (int i = 31; i >= 0; i--) {
            while (p->next[i] != nullptr && p->next[i]->val < num) p = p->next[i];
            update[i] = p;
        }
        if (p->next[0] == nullptr || p->next[0]->val != num) return false;
        p = p->next[0];
        int level = p->next.size();
        for (int i = 0; i < level; i++) update[i]->next[i] = p->next[i];
        delete p;
        return true;
    }

    void output() {
        Node *p = head;
        while (p->next[0] != nullptr) {
            cout << p->next[0]->val << " ";
            p = p->next[0];
        }
        cout << endl;
    }
};

int main() {
    Skiplist sp;

    sp.add(1);
    cout << "ADD\n";
    sp.output();

    sp.add(2);
    cout << "ADD\n";
    sp.output();
    
    sp.add(3);
    cout << "ADD\n";
    sp.output();

    cout << "SEARCH " << (sp.search(0) ? "SUCCESS" : "FAIL") << "\n";

    sp.add(4);
    cout << "ADD\n";
    sp.output();

    cout << "SEARCH " << (sp.search(1) ? "SUCCESS" : "FAIL") << "\n";

    sp.erase(0);
    cout << "ERASE\n";
    sp.output();

    sp.erase(1);
    cout << "ERASE\n";
    sp.output();

    sp.search(1);
    cout << "SEARCH " << (sp.search(1) ? "SUCCESS" : "FAIL") << "\n";
    return 0;
}
