/*************************************************************************
	> File Name: 1.LeetCode1785.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月16日 星期五 10时46分03秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minElements(vector<int>& nums, int limit, int goal) {
  long sum = 0;
  for (int x : nums)
    sum += x;
  long dis = abs(sum - goal);
  return ceil(dis * 1.0 / limit);
}

int main() {
  return 0;
}
