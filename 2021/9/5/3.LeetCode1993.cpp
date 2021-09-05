/*************************************************************************
	> File Name: 3.LeetCode1993.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月05日 星期日 14时44分25秒
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
    int ind;
    bool locked;
    int lock_user;
    int locked_child;
    vector<int> children;

    Node() = default;
    Node(int ind) : ind(ind), locked(false), lock_user(0), locked_child(0), children(vector<int>(0)) {}
};

class LockingTree {
public:
    vector<Node *> nodes;
    vector<int> parent;

    LockingTree(vector<int>& parent) : nodes(vector<Node *>(parent.size(), nullptr)), parent(parent) {
        int n = parent.size();
        for (int i = 0; i < n; i++) nodes[i] = new Node(i);
        for (int i = 1; i < n; i++) nodes[parent[i]]->children.push_back(i);
    }

    bool lock(int num, int user) {
        if (nodes[num]->locked) return false;
        nodes[num]->locked = true;
        nodes[num]->lock_user = user;
        while (num) {
            nodes[parent[num]]->locked_child++;
            num = parent[num];
        }
        return true;
    }

    void unlock(int num) {
        nodes[num]->locked = false;
        nodes[num]->lock_user = 0;
        while (num) {
            nodes[parent[num]]->locked_child--;
            num = parent[num];
        }
    }

    bool unlock(int num, int user) {
        if (!nodes[num]->locked || nodes[num]->lock_user != user) return false;
        unlock(num);
        return true;
    }

    void unlock_all(int num) {
        if (nodes[num]->locked) unlock(num);
        for (int x : nodes[num]->children) unlock_all(x);
    }

    bool has_locked_parent(int num) {
        while (num) {
            if (nodes[parent[num]]->locked) return true;
            num = parent[num];
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (nodes[num]->locked || !nodes[num]->locked_child || has_locked_parent(num)) return false;
        unlock_all(num);
        lock(num, user);
        return true;
    }
};

int main() {
    return 0;
}
