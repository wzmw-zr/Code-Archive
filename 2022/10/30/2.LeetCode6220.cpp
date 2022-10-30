/*************************************************************************
	> File Name: 2.LeetCode6220.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月30日 星期日 10时30分38秒
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

int averageValue(vector<int>& nums) {
  int cnt = 0;
  int sum = 0;
  for (int x : nums) {
    if (x % 3 == 0 && x % 2 == 0) {
      sum += x;
      cnt++;
    }
  }
  return cnt == 0 ? 0 : sum / cnt;
}

int main() {
  return 0;
}
