/*************************************************************************
	> File Name: 1.LeetCode429.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月08日 星期五 00时02分48秒
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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

using PNI = pair<Node *, int>;
vector<vector<int>> levelOrder(Node* root) {
  vector<vector<int>> ans;
  queue<PNI> que;
  if (root) que.push(PNI(root, 0));
  while (!que.empty()) {
    PNI temp = que.front();
    que.pop();
    if (temp.second == ans.size()) ans.push_back(vector<int>(0));
    ans[temp.second].push_back(temp.first->val);
    for (auto &&child : temp.first->children) que.push(PNI(child, temp.second + 1));
  }
  return ans;
}

int main() {
  return 0;
}
