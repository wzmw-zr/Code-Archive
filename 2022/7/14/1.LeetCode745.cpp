/*************************************************************************
	> File Name: 1.LeetCode745.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月14日 星期四 09时37分31秒
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

// TLE
struct Node {
  int end;
  unordered_map<char, Node *> next;
  set<int> inds;

  Node(int end = 0) : end(end) {}
};

struct Tire {
  Node *_root;

  Tire() : _root(new Node()) {}

  void insert(string &s, int ind) {
    Node *root = _root;
    for (char c : s) {
      if (!root->next.count(c)) root->next[c] = new Node();
      root = root->next[c];
      root->inds.insert(ind);
    }
    root->end = 1;
  }

  set<int> query(string &s) {
    Node *root = _root;
    for (char c : s) {
      if (!root->next.count(c)) return {};
      root = root->next[c];
    }
    return root->inds;
  }
};

class WordFilter {
public:
  Tire pre_tire;
  Tire suf_tire;

  WordFilter(vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
      pre_tire.insert(words[i], i);
      reverse(words[i].begin(), words[i].end());
      suf_tire.insert(words[i], i);
    }
  }

  int f(string pref, string suff) {
    set<int> pre = pre_tire.query(pref);
    set<int> suf = suf_tire.query(suff);
    vector<int> same_inds;
    for (int x : pre) {
      if (suf.count(x)) same_inds.push_back(x);
    }
    sort(same_inds.begin(), same_inds.end());
    if (!same_inds.size()) return -1;
    return *(same_inds.rbegin());
  }
};

int main() {
  return 0;
}
