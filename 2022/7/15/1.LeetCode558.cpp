/*************************************************************************
	> File Name: 1.LeetCode558.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月15日 星期五 08时19分12秒
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

// Definition for a QuadTree node.
class Node {
public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

Node* intersect(Node* quadTree1, Node* quadTree2) {
  if (quadTree1->isLeaf && quadTree2->isLeaf) {
    quadTree1->val |= quadTree2->val;
    return quadTree1;
  }
  if (quadTree1->isLeaf && !quadTree2->isLeaf) {
    quadTree1->isLeaf = false;
    quadTree1->topLeft = new Node(quadTree1->val, true);
    quadTree1->topRight= new Node(quadTree1->val, true);
    quadTree1->bottomLeft = new Node(quadTree1->val, true);
    quadTree1->bottomRight = new Node(quadTree1->val, true);
  }
  if (!quadTree1->isLeaf && quadTree2->isLeaf) {
    quadTree2->isLeaf = false;
    quadTree2->topLeft = new Node(quadTree2->val, true);
    quadTree2->topRight= new Node(quadTree2->val, true);
    quadTree2->bottomLeft = new Node(quadTree2->val, true);
    quadTree2->bottomRight = new Node(quadTree2->val, true);
  }
  quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
  quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
  quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
  quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
  quadTree1->val = true;
  if (quadTree1->topLeft->isLeaf && quadTree1->topRight->isLeaf && quadTree1->bottomLeft->isLeaf && quadTree1->bottomRight->isLeaf && quadTree1->topLeft->val == quadTree1->topRight->val && quadTree1->topLeft->val == quadTree1->bottomLeft->val && quadTree1->topLeft->val == quadTree1->bottomRight->val) {
    quadTree1->val = quadTree1->topLeft->val;
    quadTree1->topLeft = nullptr;
    quadTree1->topRight = nullptr;
    quadTree1->bottomLeft = nullptr;
    quadTree1->bottomRight = nullptr;
    quadTree1->isLeaf = true;
  }
  return quadTree1;
}

int main() {
  return 0;
}
