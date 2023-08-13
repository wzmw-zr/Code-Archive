/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月13日 星期日 19时21分43秒
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
#include <functional>
using namespace std;

struct Node {
  string name;
  vector<Node *> next;

  Node() = default;
  Node(string name) : name(name), next(vector<Node *>(0)) {}
};

int get_level(string &s) {
  int ind = 0;
  while (s[ind] && s[ind] == '-')
    ind++;
  return ind;
}

string get_name(string &s) {
  int ind = 0;
  while (s[ind] && s[ind] == '-')
    ind++;
  return s.substr(ind);
}

int main() {
  string key;
  int n;
  cin >> key >> n;
  vector<string> lines(n);
  for (int i = 0; i < n; i++)
    cin >> lines[i];

  if (n == 0) {
    cout <<  "No Files Found" << endl;
    return 0;
  }

  function<Node *(int, int)> dfs = [&](int ind, int right) -> Node * {
    if (ind == right)
      return new Node(get_name(lines[ind]));
    int level = get_level(lines[ind]);
    vector<int> next_levels;
    for (int i = ind + 1; i <= right; i++) {
      if (get_level(lines[i]) == level + 1)
        next_levels.push_back(i);
    }
    Node *root = new Node(get_name(lines[ind]));
    next_levels.push_back(right + 1);
    int m = next_levels.size();
    for (int i = 0; i < m - 1; i++)
      root->next.push_back(dfs(next_levels[i], next_levels[i + 1] - 1));
    return root;
  };
  Node *root = dfs(0, n - 1);


  int flag = 0;

  vector<string> path;
  function<void(Node *)> dfs2 = [&](Node *_root) {
    path.push_back(_root->name);
    if (_root->name.find(key) != string::npos) {
      string s = "/";
      for (auto && x : path)
        s += x;
      cout << s << endl;
      flag = 1;
    } 
    for (Node *next : _root->next)
      dfs2(next);
    path.pop_back();
  };

  dfs2(root);

  if (!flag)
    cout <<  "No Files Found" << endl;
  return 0;
}
