/*************************************************************************
	> File Name: 3.LeetCode1065.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月03日 星期二 07时49分32秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct Node {
    map<char, Node *> mp;
    bool end;

    Node() : end(false) {}
};

struct Tire {
    Node *__root;
    Tire() : __root(new Node()) {}

    void __insert(Node *root, string &s) {
        for (int i = 0; s[i]; i++) {
            if (!(root->mp.count(s[i]))) root->mp[s[i]] = new Node();
            root = root->mp[s[i]];
        }
        root->end = true;
    }

    void insert(string s) {
        __insert(__root, s);
    }

    bool __find(Node *root, string &s) {
        for (int i = 0; s[i]; i++) {
            if (!(root->mp.count(s[i]))) return false;
            root = root->mp[s[i]];
        }
        return root->end;
    }

    bool find(string s) {
        return __find(__root, s);
    }

    void __erase(Node *root) {
        if (!root) return ;
        for (auto &x : root->mp) __erase(x.second);
        delete root;
    }

    ~Tire() {
        __erase(__root);
    }
};

vector<vector<int>> indexPairs(string text, vector<string>& words) {
    Tire tire;
    int n = words.size(), m = text.size();
    vector<vector<int>> ans;
    vector<int> temp(2);
    for (int i = 0; i < n; i++) tire.insert(words[i]);
    for (int i = 0; i < m; i++) {
        for (int j = 1; i + j - 1 < m; j++) {
            if (tire.find(text.substr(i, j))) {
                temp[0] = i, temp[1] = i + j - 1;
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

int main() {
    string text, word;
    vector<string> words;
    cin >> text;
    while (cin >> word) words.push_back(word);
    auto ans = indexPairs(text, words);
    for (auto &x : ans) {
        cout << "[";
        for (auto &y : x) cout << y << " ";
        cout << "]" << endl;
    }
    return 0;
}
