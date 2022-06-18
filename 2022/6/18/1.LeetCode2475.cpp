/*************************************************************************
	> File Name: 1.LeetCode2475.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月18日 星期六 09时30分51秒
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

class Node {
public:
  int val;
  Node* next;

  Node() {}

  Node(int _val) {
    val = _val;
    next = NULL;
  }

  Node(int _val, Node* _next) {
    val = _val;
    next = _next;
  }
};

Node* insert(Node* head, int insertVal) {
  if (!head) {
    Node *head = new Node(insertVal);
    head->next = head;
    return head;
  }
  Node *node = head;
  int flag = 1;
  while (!(node->val <= insertVal && node->next->val >= insertVal)) {
    node = node->next;
    if (node == head) {
      flag = 0;
      break;
    }
  }
  if (!flag) {
    while (node->val <= node->next->val) {
      node = node->next; 
      if (node == head) break;
    }
  }
  Node *temp = new Node(insertVal, node->next);
  node->next = temp;
  return head;
}

int main() {
  return 0;
}
