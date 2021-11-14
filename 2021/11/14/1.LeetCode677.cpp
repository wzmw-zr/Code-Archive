/*************************************************************************
	> File Name: 1.LeetCode677.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月14日 星期日 08时41分49秒
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
    int sum;
    unordered_map<char, Node *> mp;

    Node() : val(0), sum(0) {}
    Node(int val) : val(val), sum(val) {}
};

class MapSum {
public:
    Node *_root;

    MapSum() : _root(new Node()) {}

    void insert(string key, int val) {
        Node *root = _root;
        vector<Node *> pre({root});
        for (char c : key) {
            if (!root->mp.count(c)) root->mp[c] = new Node();
            root = root->mp[c];
            pre.push_back(root);
        }
        int n = pre.size();
        // pre[n - 1]->sum = pre[n - 1]->sum - pre[n - 1]->val + val;
        pre[n - 1]->val = val;
        for (int i = n - 1; i >= 0; i--) {
            pre[i]->sum = pre[i]->val;
            for (auto &&[ch, next] : pre[i]->mp) pre[i]->sum += next->sum;
        }
    }

    int sum(string prefix) {
        Node *root = _root;
        for (char c : prefix) {
            if (!root->mp.count(c)) return 0;
            root = root->mp[c];
        }
        return root->sum;
    }
};

int main() {
    return 0;
}
