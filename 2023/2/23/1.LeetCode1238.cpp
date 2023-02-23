/*************************************************************************
	> File Name: 1.LeetCode1238.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月23日 星期四 14时30分45秒
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

vector<int> circularPermutation(int n, int start) {
  vector<int> nums({0, 1});
  for (int i = 2; i <= n; i++) {
    int len = nums.size();
    for (int j = len - 1; j >= 0; j--)
      nums.push_back(nums[j] + (1 << (i - 1)));
  }
  vector<int> ans;
  int ind = 0;
  while (nums[ind] != start)
    ind++;
  for (int i = ind; i < nums.size(); i++)
    ans.push_back(nums[i]);
  for (int i = 0; i < ind; i++)
    ans.push_back(nums[i]);
  return ans;
}

int main() {
  return 0;
}
