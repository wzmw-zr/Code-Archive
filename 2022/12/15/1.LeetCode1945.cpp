/*************************************************************************
	> File Name: 1.LeetCode1945.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月15日 星期四 10时35分32秒
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

int getLucky(string s, int k) {
  string nums = "";
  for (char c : s)
    nums += to_string(int(c - 'a' + 1));
  while (k) {
    int sum = 0;
    for (char c : nums)
      sum += c - '0';
    nums = to_string(sum);
    k--;
  }
  return stoi(nums);
}

int main() {
  return 0;
}
