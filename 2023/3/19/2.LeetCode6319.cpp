/*************************************************************************
	> File Name: 2.LeetCode6319.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月19日 星期日 10时32分42秒
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

vector<int> evenOddBit(int n) {
  vector<int> ans(2, 0);
  for (int i = 0; i < 31; i++) {
    if (n & (1 << i))
      ans[i & 1]++;
  }
  return ans;
}

int main() {
  return 0;
}
