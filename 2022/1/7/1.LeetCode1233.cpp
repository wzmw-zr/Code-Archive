/*************************************************************************
	> File Name: 1.LeetCode1233.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月07日 星期五 09时46分26秒
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
    bool end;
    unordered_map<string, Node *> next;

    Node() : end(false), next(unordered_map<string, Node *>()) {}
    Node(bool end) : end(end), next(unordered_map<string, Node *>()) {}
};

struct Trie {
    Node *root_;

    Trie() : root_(new Node()) {}

    void insert(string s) {
        Node *root = root_;
        int ind = 0;
        while (s[ind]) {
            while (s[ind] && s[ind] == '/') ind++;
            string temp = "";
            while (s[ind] && s[ind] != '/') temp += s[ind++];
            if (temp == "") continue;
            if (!root->next.count(temp)) root->next[temp] = new Node();
            root = root->next[temp];
        }
        root->end = true;
    }
};

void dfs(Node *root, vector<string> &path, vector<string> &ans) {
    if (!root) return ;
    if (root->end) {
        string temp = "";
        for (string s : path) temp += "/" + s;
        ans.push_back(temp);
        return ;
    }
    for (auto &&[s, next] : root->next) {
        path.push_back(s);
        dfs(next, path, ans);
        path.pop_back();
    }
}

vector<string> removeSubfolders(vector<string>& folder) {
    Trie trie;
    for (string s : folder) trie.insert(s);
    vector<string> path;
    vector<string> ans;
    dfs(trie.root_, path, ans);
    return ans;
}

int main() {
    return 0;
}
