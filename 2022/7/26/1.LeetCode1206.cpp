/*************************************************************************
	> File Name: 1.LeetCode1206.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月26日 星期二 11时30分16秒
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

// I don't know why TLE....
#define MAX_L 20

struct Node {
  int val;
  int level;
  vector<Node *> next;

  Node() = default;
  Node(int val, int level) : val(val), level(level), next(vector<Node *>(level, nullptr)) {}
};

class Skiplist {
public:
  Node *_head;

  Skiplist() : _head(new Node(-1, MAX_L)) {
    srand(time(0));
  }

  bool search(int target) {
    Node *node = _head;
    vector<Node *> path(MAX_L);
    for (int lvl = MAX_L - 1; lvl >= 0; lvl--) {
      while (node->next[lvl] && node->next[lvl]->val < target)
        node = node->next[lvl];
      path[lvl] = node;
    }
    if (path[0]->next[0] && path[0]->next[0]->val == target) return true;
    return false;
  }

  void add(int num) {
    Node *node = _head;
    vector<Node *> path(MAX_L);
    for (int lvl = MAX_L - 1; lvl >= 0; lvl--) {
      while (node->next[lvl] && node->next[lvl]->val < num)
        node = node->next[lvl];
      path[lvl] = node;
    }
    int level = 1;
    while (level < MAX_L) {
      if (rand() & 1) level++;
    }
    Node *temp = new Node(num, level);
    for (int lvl = 0; lvl < level; lvl++) {
      temp->next[lvl] = path[lvl]->next[lvl];
      path[lvl]->next[lvl] = temp;
    }
  }

  bool erase(int num) {
    Node *node = _head;
    vector<Node *> path(MAX_L);
    for (int lvl = MAX_L - 1; lvl >= 0; lvl--) {
      while (node->next[lvl] && node->next[lvl]->val < num)
        node = node->next[lvl];
      path[lvl] = node;
    }
    if (path[0]->next[0] && path[0]->next[0]->val == num) {
      Node *temp = path[0]->next[0];
      int level = temp->level;
      for (int lvl = 0; lvl < level; lvl++) {
        path[lvl]->next[lvl] = temp->next[lvl];
      }
      return true;
    }
    return false;
  }
};

int main() {
  return 0;
}
