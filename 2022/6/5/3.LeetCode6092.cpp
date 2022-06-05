/*************************************************************************
	> File Name: 3.LeetCode6092.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月05日 星期日 10时39分46秒
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

vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
  unordered_map<int, int> mp;
  for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
  for (auto && op : operations) {
    int x = op[0], y = op[1];
    int ind = mp[op[0]];
    mp.erase(op[0]);
    mp[op[1]] = ind;
  }
  for (auto && [x, ind] : mp) nums[ind] = x;
  return nums;
}

int main() {
  return 0;
}
