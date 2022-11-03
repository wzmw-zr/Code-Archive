/*************************************************************************
	> File Name: 1.LeetCode1668.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月03日 星期四 10时07分58秒
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

int maxRepeating(string sequence, string word) {
  int ans = 0;
  string s = word;
  while (sequence.find(s) != string::npos) {
    ans++;
    s += word;
  }
  return ans;
}

int main() {
  return 0;
}
