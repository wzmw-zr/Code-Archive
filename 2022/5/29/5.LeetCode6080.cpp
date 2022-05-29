/*************************************************************************
	> File Name: 5.LeetCode6080.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月29日 星期日 11时02分43秒
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

int totalSteps(vector<int>& nums) {
  int cnt = 0;
  while (1) {
    vector<int> temp;
    temp.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i - 1] > nums[i]) continue;
      temp.push_back(nums[i]);
    }
    if (temp.size() == nums.size()) break;
    nums = temp;
    cnt++;
  }
  return cnt;
}

int main() {
  return 0;
}
