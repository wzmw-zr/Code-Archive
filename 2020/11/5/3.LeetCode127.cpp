/*************************************************************************
	> File Name: 3.LeetCode127.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月05日 星期四 08时01分53秒
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
    vector<Node *> next;
    int level;

    Node() = default;
    Node(const string &str) : str(str), level(1) {}
};

void build(unordered_map<string, Node *> &mp) {
    unordered_map<string, Node *> mp_t;
    for (auto &x : mp) {
        for (int i = 0; x.first[i]; i++) {
            string temp = x.first;
            temp[i] = '*';
            if (!mp_t.count(temp)) mp_t[temp] = new Node(temp);
            x.second->next.push_back(mp_t[temp]);
            mp_t[temp]->next.push_back(x.second);
        }
    }
    for (auto &x : mp_t) mp.insert(x);
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, Node *> mp;
    unordered_set<Node *> st;
    for (auto &x : wordList) mp[x] = new Node(x);
    mp[beginWord] = new Node(beginWord);
    if (!mp.count(endWord)) return 0;
    build(mp);
    //for (auto &x : mp) cout << x.first << endl;
    queue<Node *> que;
    que.push(mp[beginWord]);
    st.insert(mp[beginWord]);
    while (!que.empty()) {
        Node *temp = que.front();
        cout << temp->str << " " << temp->level << endl;
        que.pop();
        if (temp->str == endWord) return temp->level;
        for (Node *&x : temp->next) {
            for (Node *&y : x->next) {
                if (y == temp) continue;
                if (st.count(y)) continue;
                st.insert(y);
                y->level = temp->level + 1;
                que.push(y);
            }
        }
    }
    return 0;
}

int main() {
    string beginWord, endWord, word;
    vector<string> wordList;
    cin >> beginWord >> endWord;
    while (cin >> word) wordList.push_back(word);
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
