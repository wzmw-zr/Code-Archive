/*************************************************************************
	> File Name: 1.LeetCode398.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月25日 星期一 08时35分18秒
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
#include <ctime>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

class Solution {
public:
  map<int, vector<int>> mp;

  Solution(vector<int>& nums) {
    srand(time(0));
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (!mp.count(nums[i])) mp[nums[i]] = vector<int>();
      mp[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    int ind = rand() % mp[target].size();
    return mp[target][ind];
  }
};

int main() {
  return 0;
}
