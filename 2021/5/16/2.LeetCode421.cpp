/*************************************************************************
	> File Name: 2.LeetCode421.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月16日 星期日 00时35分58秒
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
    Node *one;
    Node *zero;
    Node() : one(nullptr), zero(nullptr) {}
};

struct Tire {
    Node *root;
    Tire() : root(new Node()) {}

    void insert(int x) {
        Node *temp = root;
        for (int i = 31; i >= 0; i--) {
            if (x & (1 << i)) {
                if (!temp->one) temp->one = new Node();
                temp = temp->one;
            } else {
                if (!temp->zero) temp->zero = new Node();
                temp = temp->zero;
            }
        }
    }

    int search(int x) {
        Node *temp = root;
        for (int i = 31; i >= 0; i--) {
            if (x & (1 << i)) {
                if (temp->zero) temp = temp->zero;
                else x -= (1 << i), temp = temp->one;
            } else {
                if (temp->one) x += (1 << i), temp = temp->one;
                else temp = temp->zero;
            }
        }
        return x;
    }

    void erase(Node *root) {
        if (!root) return ;
        erase(root->one);
        erase(root->zero);
        delete root;
    }

    ~Tire() {
        erase(root);
    }
};


int findMaximumXOR(vector<int>& nums) {
    Tire *tree = new Tire();
    int ans = 0;
    for (int x : nums) {
        tree->insert(x);
        ans = max(ans, tree->search(x));
    }
    return ans;
}

int main() {
    return 0;
}
