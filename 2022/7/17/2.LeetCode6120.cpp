/*************************************************************************
	> File Name: 1.LeetCode6120.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月17日 星期日 10时30分46秒
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

vector<int> numberOfPairs(vector<int>& nums) {
  unordered_map<int, int> mp;
  for (int x : nums) mp[x]++;
  vector<int> ans(2, 0);
  for (auto && [x, cnt] : mp) {
    ans[0] += cnt / 2;
    ans[1] += cnt % 2;
  }
  return ans;
}

int main() {
  return 0;
}
