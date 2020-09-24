/*************************************************************************
	> File Name: 2.Tire.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月15日 星期二 08时55分44秒
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
    bool end;
    map<char, Node *> mp;

    Node() : end(false) {}
    Node(bool status) : end(status) {}
};

struct Tire {
    Node *__root;

    Tire() : __root(new Node()) {}

    void __insert(Node *root, string s, int ind) {
        if (ind == s.size()) {
            root->end = true;
            return ;
        }
        if (root->mp.find(s[ind]) == root->mp.end()) root->mp[s[ind]] = new Node();
        __insert(root->mp[s[ind]], s, ind + 1);
    }

    void insert(string s) {
        __insert(__root, s, 0);
    }

    bool __find(Node *root, string s, int ind) {
        if (ind == s.size()) return root->end;
        if (!root) return false;
        if (root->mp.find(s[ind]) == root->mp.end()) return false;
        return __find(root->mp[s[ind]], s, ind + 1);
    }

    bool find(string s) {
        return __find(__root, s, 0);
    }

};

int main() {
    int op;
    string s;
    Tire tire;
    while (cin >> op >> s) {
        if (op & 1) cout << (tire.find(s) ? "Find" : "Miss") << endl; 
        else tire.insert(s);
    }
    return 0;
}
