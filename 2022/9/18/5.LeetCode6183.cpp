/*************************************************************************
	> File Name: 5.LeetCode6183.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月18日 星期日 10时43分02秒
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
  int end;
  int cnt;
  unordered_map<char, Node *> mp;

  Node() = default;
  Node(int end, int cnt) : end(end), cnt(cnt) {}
};

struct Trie {
  Node *_root;

  Trie() : _root(new Node(0, 0)) {}

  void insert(string &s) {
    Node *root = _root;
    for (int i = 0; s[i]; i++) {
      if (!root->mp.count(s[i]))
        root->mp[s[i]] = new Node(0, 0);
      root->mp[s[i]]->cnt++;
      root = root->mp[s[i]];
    }
    root->end = 1;
  }

  int query(string &s) {
    int ans = 0;
    Node *root = _root;
    for (int i = 0; s[i]; i++) {
      ans += root->cnt;
      root = root->mp[s[i]];
    }
    ans += root->cnt;
    return ans;
  }
};

vector<int> sumPrefixScores(vector<string>& words) {
  vector<string> sorted_words(words.begin(), words.end());
  sort(
    sorted_words.begin(),
    sorted_words.end(),
    [](string &a, string &b) {
      return a.size() < b.size();
    }
  );
  Trie trie;
  for (string &word : sorted_words) 
    trie.insert(word);
  vector<int> ans;
  for (string &word : words) 
    ans.push_back(trie.query(word));
  return ans;
}

int main() {
  return 0;
}
