/*************************************************************************
	> File Name: 2.LeetCode1268.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月08日 星期六 09时20分22秒
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
    set<string> top;

    Node() = default;
};

struct Trie {
    Node *root_;

    Trie() : root_(new Node()) {}

    void insert(string &product) {
        Node *root = root_;
        for (char c : product) {
            root->top.insert(product);
            if (root->top.size() > 3) root->top.erase(prev(root->top.end()));
            if (!root->next.count(c)) root->next[c] = new Node();
            root = root->next[c];
        }
        root->top.insert(product);
        if (root->top.size() > 3) root->top.erase(prev(root->top.end()));
    }

    void search(string &searchWord, vector<vector<string>> &ans) {
        Node *root = root_;
        for (char c : searchWord) {
            if (!root->next.count(c)) root->next[c] = new Node();
            root = root->next[c];
            ans.push_back(vector<string>(root->top.begin(), root->top.end()));
        }
    }
};

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    Trie trie;
    for (string product : products) trie.insert(product);
    vector<vector<string>> ans;
    trie.search(searchWord, ans);
    return ans;
}

int main() {
    return 0;
}
