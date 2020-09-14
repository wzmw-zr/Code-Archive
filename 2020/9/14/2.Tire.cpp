/*************************************************************************
	> File Name: 2.Tire.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月14日 星期一 15时17分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<ctime>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct Node {
    bool end;
    map<char, Node *> mp;

    Node() : end(false) {}

    void __insert(Node *root, string &s, int ind) {
        if (ind == s.size()) {
            root->end = true;
            cout << s << " " << (root->end ? "end" : "not end") << endl; 
            return ;
        }
        if (root->mp.find(s[ind]) == root->mp.end()) root->mp[s[ind]] = new Node();
        __insert(root->mp[s[ind]], s, ind + 1);
    }

    void insert(string &s) {
        __insert(this, s, 0);
    } 

    bool __find(Node *root, string &s, int ind) {
        if (ind == s.size()) {
            cout << s << " " << (root->end ? "end" : "not end") << endl; 
            return root->end;   
        }
        if (!root) return false;
        if (root->mp.find(s[ind]) == root->mp.end()) return false;
        return __find(root->mp[s[ind]], s, ind + 1);
    }

    bool find(string &s) {
        return __find(this, s, 0); 
    }
};

struct Tire {
    Node *root;   

    Tire() : root(new Node()) {};

    ~Tire() {
        delete root;
    }

    void insert(string s) {
        root->insert(s);
    }

    bool find(string s) {
        return root->find(s);
    }
};

int main() {
    srand(time(0));
    Tire tire;
    string s;
    int n;
    while (1) {
        cin >> n >> s;
        n &= 1;
        switch (n) {
            case 0 : tire.insert(s); break;
            case 1 : {
                cout << (tire.find(s) ? "Match" : "No Match") << endl;
            } break;
        }
    }
    return 0;
}
