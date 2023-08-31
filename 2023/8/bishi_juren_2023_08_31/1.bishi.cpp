/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月31日 星期四 19时39分20秒
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
  int in_deg;
  unordered_set<int> next;
  Node() : in_deg(0), next(unordered_set<int>()) {}
};

int main() {
  string str;
  getline(cin, str);
  if (str == "无") {
    cout << "No" << endl;
    return 0;
  }
  str = str.substr(1, str.size() - 2);
  int ind = 0;
  unordered_map<int, Node> mp;
  while (str[ind]) {
    while (str[ind] && str[ind] != '{') {
      ind++;
    }
    ind++;
    string num_1 = "";
    while (str[ind] && str[ind] != ' ' && str[ind] != ',') {
      num_1 += str[ind++];
    }
    ind++;
    while (str[ind] && str[ind] == ' ') {
      ind++;
    }
    string num_2 = "";
    while (str[ind] && str[ind] != ' ' && str[ind] != '}') {
      num_2 += str[ind++];
    }
    ind++;
    if (str[ind])
      ind++;
    int x = stoi(num_1);
    int y = stoi(num_2);
    if (!mp.count(x))
      mp[x] = Node();
    if (!mp.count(y))
      mp[y] = Node();
    mp[x].next.insert(y);
    mp[y].in_deg++;
  }
  queue<int> que;
  for (auto && [x, node] : mp) {
    if (node.in_deg)
      continue;
    que.push(x);
  }
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    for (int y : mp[x].next) {
      mp[y].next.erase(x);
      if (!(--mp[y].in_deg))
        que.push(y);
    }
    mp.erase(x);
  }
  cout << (mp.size() ? "No" : "Yes") << endl;
  return 0;
}
