/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月20日 星期日 19时05分00秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstdint>
using namespace std;

long MOD = 1e4 + 7;

struct Node {
  char ops;
  Node *left;
  Node *right;

  Node() = default;
  Node(char ops) : ops(ops), left(nullptr), right(nullptr) {}
};

Node *build(string s) {
  if (s.size() == 0)
    return nullptr;
  if (s[0] == '(') {
    stack<int> st;
    int n = s.size();
    st.push('(');
    for (int i = 1; i < n; i++) {
      if (s[i] == '(') {
        st.push('(');
      } else if (s[i] == ')') {
        st.pop();
        if (st.empty() && i == n - 1) {
          s = s.substr(1, n - 2);
        }
      } 
    }
  }
  int n = s.size();
  vector<long> priors(n, INT32_MAX);
  long val = 0;
  long offset = 0;
  long mmin = INT32_MAX;
  for (int i = 0; i < n; i++) {
    if (s[i] == '+') {
      priors[i] = offset;
    } else if (s[i] == '(') {
      offset += 1e5;
    } else if (s[i] == ')') {
      offset -= 1e5;
    } else {
      priors[i] = offset + 1;
    }
    mmin = min(mmin, priors[i]);
  }
  for (int i = 0; i < n; i++) {
    if (priors[i] == mmin) {
      Node *root = new Node(s[i]);
      root->left = build(s.substr(0, i));
      root->right = build(s.substr(i + 1));
      return root;
    }
  }
  return nullptr;
}

unordered_map<Node *, long> mp[2];

long dfs(Node *root, int target) {
  if (!root)
    return 1;
  if (mp[target].count(root))
    return mp[target][root];
  long l_0 = dfs(root->left, 0);
  long l_1 = dfs(root->left, 1);
  long r_0 = dfs(root->right, 0);
  long r_1 = dfs(root->right, 1);
  long ans = 0;
  if (root->ops == '+') {
    if (target == 1) {
      ans = (l_0 * r_1 + l_1 * r_0 + l_1 * r_1) % MOD;
    } else {
      ans = l_0 * r_0 % MOD;
    }
  } else {
    if (target == 1) {
      ans = l_1 * r_1 % MOD;
    } else {
      ans = (l_0 * r_1 + l_1 * r_0 + l_0 * r_0) % MOD;
    }
  }
  return mp[target][root] = ans;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  Node *root = build(s);
  cout << dfs(root, 0) << endl;
  return 0;
}
