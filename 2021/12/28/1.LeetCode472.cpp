/*************************************************************************
	> File Name: 1.LeetCode472.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月28日 星期二 08时48分05秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
    unordered_map<char, Node *> next;
    bool end;

    Node() : next(unordered_map<char, Node *>()), end(false) {}
};

struct Trie {
    Node *root_;

    Trie() : root_(new Node()) {}

    void insert(string s) {
        Node *root = root_;
        for (char c : s) {
            if (!root->next.count(c)) root->next[c] = new Node();
            root = root->next[c];
        }
        root->end = true;
    }

    bool dfs(Node *root, string &s, int ind, unordered_map<int, bool> &mp) {
        if (mp.count(ind)) return mp[ind];
        int temp = ind;
        while (s[ind] && root) {
            if (!root->next.count(s[ind])) return mp[temp] = false;
            root = root->next[s[ind]];
            ind++;
            if (root->end) {
                if (dfs(root_, s, ind, mp)) return mp[temp] = true;
            }
        }
        if (!s[ind] && root && root->end) return mp[temp] = true;
        return mp[temp] = false;
    }

    bool can_build(string &s) {
        unordered_map<int, bool> mp;
        return dfs(root_, s, 0, mp);
    }
};

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    auto cmp = [](string &a, string &b) {
        return a.size() < b.size();
    };
    sort(words.begin(), words.end(), cmp);
    Trie trie;
    vector<string> ans;
    for (string word : words) {
        if (trie.can_build(word)) ans.push_back(word);
        trie.insert(word);
    }
    return ans;
}

int main() {
    vector<string> words;
    string word;
    while (cin >> word) words.push_back(word);
    auto ans = findAllConcatenatedWordsInADict(words);
    for (auto s : ans) cout << s << " ";
    cout << endl;
    return 0;
}
