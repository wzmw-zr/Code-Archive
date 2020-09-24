/*************************************************************************
	> File Name: 3.AC.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月15日 星期二 14时27分01秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

struct Node {
    bool is_end;
    map<char, Node *> mp;

    Node() : is_end(false) {}
};

struct ACTire {
    Node *__root;
    map<Node *, char> fail;

    ACTire() : __root(new Node()) {}

    void __insert(Node *root, string &s, int ind) {
        if (ind == s.size()) {
            root->is_end = true;
            return ;
        }
        if (root->mp.find(s[ind]) == root->mp.end()) root->mp[s[ind]] = new Node();
        __insert(root->mp[s[ind]], s, ind + 1);
    }

    void insert(string s) {
        __insert(__root, s, 0);
    }

    void __build(Node *root, map<Node *, char> &fail) {
        queue<Node *> que;

        for (auto &x : root->mp) que.push(x.second);
    }

    void build() {
        __build(__root, fail);
    }
};

int main() {
    return 0;
}
