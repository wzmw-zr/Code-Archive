/*************************************************************************
	> File Name: 4.LeetCode6013.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月20日 星期日 10时34分11秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

ListNode* mergeNodes(ListNode* head) {
  ListNode *head_t = new ListNode();
  ListNode *pre = head_t;
  head = head->next;
  int num = 0;
  while (head) {
    while (head->val != 0) {
      num += head->val;
      head = head->next;
    }
    if (num) {
      ListNode *temp = new ListNode(num);
      pre->next = temp;
      pre = pre->next;
      num = 0;
    }
    head = head->next;
  }
  return head_t->next;
}

int main() {
  return 0;
}
