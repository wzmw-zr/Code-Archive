/*************************************************************************
	> File Name: 2.LeetCode1755.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月16日 星期五 16时09分17秒
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

// WA
int minAbsDifference(vector<int>& nums, int goal) {
  int n = nums.size();
  int cnt_1 = 1 << (n / 2), cnt_2 = 1 << (n - n / 2);
  vector<int> sum1(cnt_1, 0);
  vector<int> sum2(cnt_2, 0);
  for (int i = 1; i < cnt_1; i++) {
    int ind = __builtin_ctz(i);
    int pre = i - (1 << ind);
    sum1[i] = sum1[pre] + nums[ind];
  }
  for (int i = 1; i < cnt_2; i++) {
    int ind = __builtin_ctz(i);
    int pre = i - (1 << ind);
    sum2[ind] = sum2[pre] + nums[n / 2 + ind];
  }
  sort(sum1.begin(), sum1.end());
  sort(sum2.begin(), sum2.end());
  int ind_1 = 0, ind_2 = sum2.size() - 1;
  int mmin = INT32_MAX;
  while (ind_1 < sum1.size() && ind_2 >= 0) {
    int sum = sum1[ind_1] + sum2[ind_2];
    mmin = min(mmin, abs(sum - goal));
    if (sum > goal)
      ind_2--;
    else
      ind_1++;
  }
  return mmin;
}

int main() {
  return 0;
}
