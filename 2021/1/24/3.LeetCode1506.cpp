/*************************************************************************
	> File Name: 3.LeetCode1506.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月24日 星期日 00时36分50秒
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

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

Node* findRoot(vector<Node*> tree) {
    unordered_map<Node *, int> mp;
    for (auto &x : tree) mp[x] = 0;
    for (auto &x : tree) {
        for (auto &y : x->children) mp[y]++;
    }
    Node *ans = nullptr;
    for (auto &&[node, cnt] : mp) {
        if (cnt) continue;
        ans = node;
        break;
    }
    return ans;
}

int main() {
    return 0;
}
