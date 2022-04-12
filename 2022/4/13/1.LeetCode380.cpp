/*************************************************************************
	> File Name: 1.LeetCode380.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月13日 星期三 00时08分31秒
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
#include <list>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

class RandomizedSet {
public:
  unordered_map<int, list<int>::iterator> mp;
  list<int> nums;

  RandomizedSet() {
    srand(time(0));
  }

  bool insert(int val) {
    if (mp.count(val)) return false;
    nums.push_back(val);
    mp[val] = prev(nums.end());
    return true;
  }

  bool remove(int val) {
    if (!mp.count(val)) return false;
    nums.erase(mp[val]);
    mp.erase(val);
    return true;
  }

  int getRandom() {
    int ind = rand() % nums.size();
    auto iter = nums.begin();
    for (int i = 0; i < ind; i++) iter = next(iter);
    return *iter;
  }
};

int main() {
  return 0;
}
