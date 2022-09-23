/*************************************************************************
	> File Name: 1.LeetCode707.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月23日 星期五 08时07分05秒
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
  Node *next;
  Node *prev;

  Node() : val(0), next(nullptr), prev(nullptr) {}
  Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
public:
  Node *_head;
  Node *_tail;

  MyLinkedList() : _head(new Node()), _tail(new Node()) {
    _head->next = _tail;
    _tail->prev = _head;
  }

  int get(int index) {
    Node *node = _head->next;
    int ind = 0;
    while (ind != index && node != _tail) {
      node = node->next;
      ind++;
    }
    if (node == _tail)
      return -1;
    return node->val;
  }

  void addAtHead(int val) {
    Node *node = new Node(val);
    node->next = _head->next;
    _head->next->prev = node;
    node->prev = _head;
    _head->next = node;
  }

  void addAtTail(int val) {
    Node *node = new Node(val);
    node->prev = _tail->prev;
    _tail->prev->next = node;
    node->next = _tail;
    _tail->prev = node;
  }

  void addAtIndex(int index, int val) {
    if (index < 0) {
      addAtHead(val);
      return ;
    }
    int ind = 0;
    Node *node = _head->next;
    while (ind != index && node != _tail) {
      node = node->next;
      ind++;
    }
    if (node == _tail && ind == index) {
      addAtTail(val);
      return ;
    }
    if (node == _tail && ind != index) 
      return ;
    Node *temp = new Node(val);
    temp->prev = node->prev;
    node->prev->next = temp;
    temp->next = node;
    node->prev = temp;
  }

  void deleteAtIndex(int index) {
    if (index < 0)
      return ;
    int ind = 0;
    Node *node = _head->next;
    while (ind != index && node != _tail) {
      node = node->next;
      ind++;
    }
    if (node == _tail)
      return ;
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = node->next;
    next->prev = node->prev;
    delete node;
  }
};

int main() {
  return 0;
}
