/*************************************************************************
	> File Name: 2.LeetCode1650.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月22日 星期日 00时24分22秒
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
    Node *left;
    Node *right;
    Node *parent;
    Node(Node *_parent = nullptr) : val(0), left(nullptr), right(nullptr), parent(_parent) {}
    Node(int val, Node *_parent = nullptr) : val(val), left(nullptr), right(nullptr), parent(_parent) {}
};

Node* lowestCommonAncestor(Node* p, Node * q) {
    vector<Node *> path_p, path_q;
    while (p) {
        path_p.push_back(p);  
        p = p->parent;
    }
    while (q) {
        path_q.push_back(q);
        q = q->parent;
    }
    Node *ans = nullptr;
    for (int i = path_p.size() - 1, j = path_q.size() - 1; i >= 0 && j >= 0; i--, j--) {
        if (path_p[i] == path_q[j]) ans = path_p[i];
        else break;
    }
    return ans;
}

int main() {
    return 0;
}
