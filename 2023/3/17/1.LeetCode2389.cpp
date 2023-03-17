/*************************************************************************
	> File Name: 1.LeetCode2389.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月17日 星期五 09时39分54秒
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

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
  int n = nums.size(), m = queries.size();
  sort(nums.begin(), nums.end());
  for (int i = 1; i < n; i++)
    nums[i] += nums[i - 1];
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (nums[mid] <= queries[i])
        l = mid;
      else
        r = mid - 1;
    }
    ans.push_back(nums[l] <= queries[i] ? l + 1 : l);
  }
  return ans;
}

int main() {
  return 0;
}
