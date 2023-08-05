/*************************************************************************
	> File Name: 1.LeetCode6940.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月05日 星期六 22时34分27秒
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
  ListNode *temp = head;
  while (temp && temp->next) {
    int x = gcd(temp->val, temp->next->val);
    ListNode *node = new ListNode(x);
    node->next = temp->next;
    temp->next = node;
    temp = temp->next->next;
  }
  return head;
}

int main() {
  return 0;
}
