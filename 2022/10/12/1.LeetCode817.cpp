/*************************************************************************
	> File Name: 1.LeetCode817.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月12日 星期三 09时21分05秒
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

int numComponents(ListNode* head, vector<int>& nums) {
  vector<int> list_nums;
  while (head) {
    list_nums.push_back(head->val);
    head = head->next;
  }
  unordered_map<int, int> mp;
  for (int i = 0; i < nums.size(); i++)
    mp[nums[i]] = i;
  int n = list_nums.size(), ind = 0;
  int ans = 0;
  while (ind < n) {
    if (mp.count(list_nums[ind]))
      ans++;
    while (ind < n && mp.count(list_nums[ind])) 
      ind++;
    if (ind < n)
      ind++;
  }
  return ans;
}

int main() {
  return 0;
}
