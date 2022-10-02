/*************************************************************************
	> File Name: 4.LeetCode6194.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月02日 星期日 10时55分39秒
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

int minimizeXor(int num1, int num2) {
  int n = __builtin_popcount(num2);
  vector<int> one_inds, zero_inds;
  for (int i = 0; i <= 31; i++) {
    if (num1 & (1 << i))
      one_inds.push_back(i);
    else
      zero_inds.push_back(i);
  }
  reverse(zero_inds.begin(), zero_inds.end());
  int ans = 0;
  while (n && one_inds.size()) {
    int ind = *one_inds.rbegin();
    ans |= (1 << ind);
    one_inds.pop_back();
    n--;
  }
  while (n && zero_inds.size()) {
    int ind = *zero_inds.rbegin();
    ans |= (1 << ind);
    zero_inds.pop_back();
    n--;
  }
  return ans;
}

int main() {
  return 0;
}
