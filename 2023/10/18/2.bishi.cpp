/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月18日 星期三 19时27分59秒
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
  int type;
  int value1;
  int value2;

  Node() = default;
  Node(int type, int value1, int value2 = -1) : type(type), value1(value1), value2(value2) {}
};

using PII = pair<int, int>;

set<PII> path;

int dfs1(int a, map<PII, int> &mp, vector<vector<Node>> &ops, vector<int> &target, vector<int> &check, int &flag);
int dfs2(int a, int b, map<PII, int> &mp, vector<vector<Node>> &ops, vector<int> &target, vector<int> &check, int &flag);

int dfs1(int a, map<PII, int> &mp, vector<vector<Node>> &ops, vector<int> &target, vector<int> &check, int &flag) {
  if (!flag)
    return -1;
  if (check[a])
    return target[a];
  int m = ops[a].size();
  for (int i = 0; i < m && flag; i++)
    dfs2(a, i, mp, ops, target, check, flag);
  check[a] = 1;
  return target[a] = flag ? mp[PII(a, m - 1)] : -1;
}

int dfs2(int a, int b, map<PII, int> &mp, vector<vector<Node>> &ops, vector<int> &target, vector<int> &check, int &flag) {
  PII state(a, b);
  if (path.count(state)) {
    flag = 0;
    mp[state] = -1;
  }
  if (!flag)
    return -1;
  if (mp.count(state))
    return mp[state];

  path.insert(state);
  auto [x, v1, v2] = ops[a][b];
  int ans;
  switch (x) {
    case 0: {
      if (v1 >= ops.size()) {
        flag = 0;
      } else {
        if (!check[v1])
          ans = dfs1(v1, mp, ops, target, check, flag);
        else
          ans = target[v1];
      }
    } break;
    case 1: {
        ans = v1;
    } break;
    case 2: {
      if (v1 >= ops[a].size() || v2 >= ops[a].size()) {
        flag = 0;
      } else {
        int x = dfs2(a, v1, mp, ops, target, check, flag);
        int y = dfs2(a, v2, mp, ops, target, check, flag);
        ans = x - y;
      }
    } break;
    case 3: {
      if (v1 >= ops[a].size() || v2 >= ops[a].size()) {
        flag = 0;
      } else {
        int x = dfs2(a, v1, mp, ops, target, check, flag);
        int y = dfs2(a, v2, mp, ops, target, check, flag);
        ans = x + y;
      }
    } break;
  }
  path.erase(state);
  return mp[state] = flag ? ans : -1;
};

int main() {
  int n;
  cin >> n;
  vector<vector<Node>> ops(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int x, value1, value2;
      cin >> x;
      switch (x) {
        case 0: {
          cin >> value1;
          ops[i].push_back(Node(x, value1));
        } break;
        case 1: {
          cin >> value1;
          ops[i].push_back(Node(x, value1));
        } break;
        case 2: {
          cin >> value1 >> value2;
          ops[i].push_back(Node(x, value1, value2));
        } break;
        case 3: {
          cin >> value1 >> value2;
          ops[i].push_back(Node(x, value1, value2));
        } break;
      }
    }
  }

  map<PII, int> mp;
  vector<int> target(n);
  vector<int> check(n, 0);
  int flag = 1;
  
  cout << dfs1(0, mp, ops, target, check, flag) << endl;
  return 0;
}
