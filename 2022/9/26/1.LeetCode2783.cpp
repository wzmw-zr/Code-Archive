/*************************************************************************
	> File Name: 1.LeetCode2783.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月26日 星期一 09时15分09秒
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

vector<int> missingTwo(vector<int>& nums) {
  int n = nums.size();
  int all_xor = 0;
  for (int x : nums)
    all_xor ^= x;
  for (int i = 1; i <= n + 2; i++)
    all_xor ^= i;
  int ind = __builtin_ctz(all_xor);
  int num_1 = 0;
  int num_2 = 0;
  for (int x : nums) {
    if (x & (1 << ind))
      num_1 ^= x;
    else
      num_2 ^= x;
  }
  for (int i = 1; i <= n + 2; i++) {
    if (i & (1 << ind))
      num_1 ^= i;
    else
      num_2 ^= i;
  }
  return {num_1, num_2};
}

int main() {
  return 0;
}
