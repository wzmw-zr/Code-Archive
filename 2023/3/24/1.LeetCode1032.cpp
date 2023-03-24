/*************************************************************************
	> File Name: 1.LeetCode1032.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月24日 星期五 09时29分34秒
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
  vector<Node *> next;
  Node *fail;
  bool is_end;

  Node() : next(vector<Node *>(26, nullptr)), fail(this), is_end(false) {}
  Node(Node *fail) : next(vector<Node *>(26, nullptr)), fail(fail), is_end(false) {}
};

struct Trie {
  Node *_root; 
  Node *root_t;

  Trie() : _root(new Node()), root_t(_root) {}

  void insert(string &word) {
    Node *root = _root;
    for (char c : word) {
      if (!root->next[c - 'a'])
        root->next[c - 'a'] = new Node(_root);
      root = root->next[c - 'a'];
    }
    root->is_end = true;
  }

  void build() {
    queue<Node *> que;
    for (auto && next : _root->next) {
      if (next)
        que.push(next);
    }
    while (!que.empty()) {
      Node *root = que.front();
      que.pop();
      for (int i = 0; i < 26; i++) {
        if (!root->next[i])
          continue;
        Node *temp = root->fail;
        Node *next = root->next[i];
        que.push(next);
        while (temp != _root && !temp->next[i])
          temp = temp->fail;
        if (temp->next[i]) {
          next->is_end |= temp->next[i]->is_end;
          next->fail = temp->next[i];
        }
      }
    }
  }

  bool query(char letter) {
    while (root_t != _root && !root_t->next[letter - 'a'])
      root_t = root_t->fail;
    if (root_t->next[letter - 'a'])
      root_t = root_t->next[letter - 'a'];
    return root_t->is_end;
  }
};

class StreamChecker {
public:
   Trie trie;

  StreamChecker(vector<string>& words) {
    for (string & word : words)
      trie.insert(word);
    trie.build();
  }

  bool query(char letter) {
    return trie.query(letter);
  }
};


int main() {
  return 0;
}
