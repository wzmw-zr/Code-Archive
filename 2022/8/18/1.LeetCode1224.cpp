/*************************************************************************
	> File Name: 1.LeetCode1224.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月18日 星期四 09时09分23秒
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

int maxEqualFreq(vector<int>& nums) {
  unordered_map<int, int> num_to_occur;
  map<int, int> occur_to_cnt;
  int mmax = 0;
  for (int i = 0; i < nums.size(); i++) {
    int x = nums[i];
    if (num_to_occur.count(x)) {
      occur_to_cnt[num_to_occur[x]]--;
      if (!occur_to_cnt[num_to_occur[x]])
        occur_to_cnt.erase(num_to_occur[x]);
      num_to_occur[x]++;
      occur_to_cnt[num_to_occur[x]]++;
    } else {
      num_to_occur[x] = 1;
      occur_to_cnt[1]++;
    }

    int unique_num = num_to_occur.size();
    if (occur_to_cnt.size() > 2)
      continue;
    if (occur_to_cnt.size() == 1 && unique_num > 1) {
      if (occur_to_cnt.begin()->first == 1)
        mmax = max(mmax, i + 1);
      continue;
    }
    if (occur_to_cnt.size() == 1 && unique_num == 1) {
      mmax = max(mmax, i + 1);
      continue;
    }
    auto first = occur_to_cnt.begin();
    auto second = next(first);
    if (first->first == 1 && first->second == 1)
      mmax = max(mmax, i + 1);
    if (second->second == 1 && second->first == first->first + 1)
      mmax = max(mmax, i + 1);
  }
  return mmax;
}

int main() {
  vector<int> nums;
  int n;
  while (cin >> n)
    nums.push_back(n);
  cout << maxEqualFreq(nums) << endl;
  return 0;
}
