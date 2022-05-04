/*************************************************************************
	> File Name: 1.LeetCoee1823.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月04日 星期三 08时35分29秒
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
  int val;
  Node *pre;
  Node *next;

  Node() = default;
  Node(int x) : val(x), pre(nullptr), next(nullptr) {}
};

int findTheWinner(int n, int k) {
  vector<Node *> nodes;
  for (int i = 1; i <= n; i++) {
    Node *node = new Node(i);
    nodes.push_back(node);
  }
  for (int i = 1; i <= n; i++) {
    nodes[i - 1]->next = nodes[i % n];
    nodes[i - 1]->pre = nodes[(n + i - 2) % n];
  }
  int cnt = n;
  Node *start = nodes[0];
  while (cnt > 1) {
    int t = k;
    while (t > 1) {
      start = start->next;
      t--;
    }
    Node *temp = start;
    start = start->next;
    temp->pre->next = temp->next;
    temp->next->pre = temp->pre;
    delete temp;
    cnt--;
  }
  return start->val;
}

int main() {
  return 0;
}
