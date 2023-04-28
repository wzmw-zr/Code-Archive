/*************************************************************************
	> File Name: 1.LeetCode1172.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月28日 星期五 09时07分29秒
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

class DinnerPlates {
public:
  int capacity;
  int next_free_id;
  unordered_map<int, stack<int>> mp;
  set<int> not_empty_stacks;
  set<int> full_stacks;
  set<int> not_full_stacks;

  DinnerPlates() = default;
  DinnerPlates(int capacity) : capacity(capacity), next_free_id(0), not_empty_stacks(set<int>()), full_stacks(set<int>()), not_full_stacks(set<int>()) {}

  void push(int val) {
    if (!not_full_stacks.size()) {
      int ind = this->next_free_id;
      mp[ind] = stack<int>();
      not_full_stacks.insert(ind);
      this->next_free_id++;
    }
    int ind = *not_full_stacks.begin();
    mp[ind].push(val);
    if (mp[ind].size() == this->capacity) {
      full_stacks.insert(ind);
      not_full_stacks.erase(ind);
    }
    not_empty_stacks.insert(ind);
  }

  int pop() {
    if (!not_empty_stacks.size())
      return -1;
    int ind = *prev(not_empty_stacks.end());
    return popAtStack(ind);
  }

  int popAtStack(int index) {
    if (!not_empty_stacks.count(index))
      return -1;
    int ans;
    if (full_stacks.count(index)) {
      ans = mp[index].top();
      mp[index].pop();
      if (!mp[index].size())
        not_empty_stacks.erase(index);
      full_stacks.erase(index);
      not_full_stacks.insert(index);
    } else {
      ans = mp[index].top();
      mp[index].pop();
      if (!mp[index].size())
        not_empty_stacks.erase(index);
    }
    return ans;
  }
};

int main() {
  return 0;
}
