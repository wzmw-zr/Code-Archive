/*************************************************************************
	> File Name: 5.LeetCode211.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月17日 星期四 13时39分50秒
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
    unordered_map<char, Node *> mp;
    bool is_end;
    Node() : is_end(false) {}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node *__root;
    WordDictionary() : __root(new Node()) {}

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *root = __root;
        for (int i = 0; word[i]; i++) {
            if (!root->mp.count(word[i])) root->mp[word[i]] = new Node();
            root = root->mp[word[i]];
        }
        root->is_end = true;
    }

    bool dfs(Node *root, string &word, int ind) {
        if (!word[ind]) return root->is_end;
        if (word[ind] != '.') {
            if (!root->mp.count(word[ind])) return false;
            return dfs(root->mp[word[ind]], word, ind + 1);
        } 
        if (!root->mp.size()) return false;
        bool ans = false;
        for (auto &&[c, next]: root->mp) {
            ans |= dfs(next, word, ind + 1);   
            if (ans) break;
        }
        return ans;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(__root, word, 0);
    }
};

int main() {
    return 0;
}
