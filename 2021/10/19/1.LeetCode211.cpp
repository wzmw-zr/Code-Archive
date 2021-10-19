/*************************************************************************
	> File Name: 1.LeetCode211.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月19日 星期二 08时41分06秒
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

struct Node {
    bool end;
    unordered_map<char, Node *> next;

    Node(bool end = false) : end() {}
};


class WordDictionary {
public:
    Node *_root;
    WordDictionary() : _root(new Node()) {}

    void addWord(string word) {
        Node *root = _root;
        for (char c : word) {
            if (!root->next.count(c)) root->next[c] = new Node();
            root = root->next[c];
        }
        root->end = true;
    }

    bool search(Node *root, string &word, int ind) {
        if (!root) return false;
        while (root && word[ind]) {
            if (word[ind] == '.') {
                for (auto [c, next] : root->next) {
                    if (search(next, word, ind + 1)) return true;
                }
                return false;
            } else {
                if (!root->next.count(word[ind])) return false;
                root = root->next[word[ind]];
            }
            ind++;
        }
        return word[ind] ? false : root->end;
    }

    bool search(string word) {
        return search(_root, word, 0);
    }
};

int main() {
    return 0;
}
