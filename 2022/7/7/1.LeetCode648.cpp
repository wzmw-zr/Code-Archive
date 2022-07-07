/*************************************************************************
	> File Name: 1.LeetCode648.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月07日 星期四 09时02分36秒
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
  int end;

  Node(int end = 0) : end(end) {}
};

struct Tire {
  Node *_root;

  Tire() : _root(new Node()) {}

  void insert(string &s) {
    Node *root = _root;
    for (char c : s) {
      if (!root->next.count(c)) root->next[c] = new Node();
      root = root->next[c];
    }
    root->end = 1;
  }
  
  string query(string &s) {
    Node *root = _root;
    string res = "";
    for (char c : s) {
      if (root->next.count(c)) {
        root = root->next[c];
        res += c;
      } else return s;
      if (root->end) break;
    }
    return res;
  }
};

string replaceWords(vector<string>& dictionary, string sentence) {
  Tire tire;
  for (string &s : dictionary) tire.insert(s);
  string ans = "";
  int ind = 0;
  while (sentence[ind]) {
    string word = "";
    while (sentence[ind] && sentence[ind] != ' ') word += sentence[ind++];
    if (sentence[ind]) ind++;
    string replace_word = tire.query(word);
    if (ans.size()) ans = ans + " " + replace_word;
    else ans = replace_word;
  }
  return ans;
}

int main() {
  return 0;
}
