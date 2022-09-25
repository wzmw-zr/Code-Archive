/*************************************************************************
	> File Name: 1.LeetCode788.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月25日 星期日 09时15分37秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int rotatedDigits(int n) {
  int cnt = 0;
  unordered_map<int, int> mp = {
    {0, 0}, 
    {1, 1},
    {2, 5},
    {5, 2},
    {6, 9},
    {8, 8},
    {9, 6}
  };
  function<int(int)> check = [&](int x) -> int {
    vector<int> nums;
    do {
      nums.push_back(x % 10);
      x /= 10;
    } while (x);
    int flag = 0;
    for (int t : nums) {
      if (!mp.count(t))
        return 0;
      if (t == 2 || t == 5 || t == 6 || t == 9)
        flag = 1;
    }
    return flag;
  };
  for (int i = 1; i <= n; i++) 
    cnt += check(i);
  return cnt;
}

int main() {
  return 0;
}
