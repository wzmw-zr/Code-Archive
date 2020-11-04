/*************************************************************************
	> File Name: 1.LeetCode127.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月05日 星期四 00时07分10秒
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
    string str;
    vector<Node *> out;

    Node() = default;
    Node(const string &str) : str(str) {}
};

void build(unordered_map<string, Node *> &mp) {
    for (auto &x : mp) {
        for (int i = 0; x.first[i]; i++) {
            string temp = x.first;
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == x.first[i]) continue;
                temp[i] = c;
                if (!mp.count(temp)) continue;
                x.second->out.push_back(mp[temp]);
            }
        }
    }
}

void dfs(unordered_map<string, Node *> &mp, unordered_set<Node *> &st, string beginWord, string &endWord, int &len, int level) {
    cout << "Word : " << beginWord << endl;
    if (beginWord == endWord) {
        len = min(len, level);
        return ;
    }
    st.insert(mp[beginWord]);
    for (auto &x : mp[beginWord]->out) {
        if (st.count(x)) continue;
        dfs(mp, st, x->str, endWord, len, level + 1);
    }
    st.erase(st.find(mp[beginWord]));
}

void output(unordered_map<string, Node *> &mp) {
    for (auto &x : mp) {
        cout << x.first << " : [";
        for (auto &y : x.second->out) cout << y->str << ", "; 
        cout << "]" << endl;
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, Node *> mp;
    for (auto &x : wordList) mp[x] = new Node(x);
    if (!mp.count(beginWord)) mp[beginWord] = new Node(beginWord);
    if (!mp.count(endWord)) return 0;
    #if 0
    for (auto &x : mp) cout << x.first << endl;
    #endif
    build(mp);
    //output(mp);
    int len = INT32_MAX;
    unordered_set<Node *> st;
    dfs(mp, st, beginWord, endWord, len, 1);
    return len == INT32_MAX ? 0 : len;
}

int main() {
    string beginWord, endWord, word;
    vector<string> wordList;
    cin >> beginWord >> endWord;
    while (cin >> word) wordList.push_back(word);
    #if 0
    cout << beginWord << endl;
    cout << endWord << endl;
    for (auto &x : wordList) cout << x << " ";
    cout << endl;
    #endif
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
