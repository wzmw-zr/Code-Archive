/*************************************************************************
	> File Name: 7.LeetCode6013.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月20日 星期日 11时32分51秒
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* mergeNodes(ListNode* head) {
  ListNode *head_t = head;
  ListNode *pre = head;
  head = head->next;
  while (head) {
    int num = 0;
    while (head->val != 0) {
      ListNode *temp = head;
      num += head->val;
      head = head->next;
      delete temp;
    }
    if (num) {
      ListNode *node = new ListNode(num);
      pre->next = node;
      pre = pre->next;
    }
    head = head->next;
  }
  ListNode *ans = head_t->next;
  delete head_t;
  return ans;
}

int main() {
  return 0;
}
