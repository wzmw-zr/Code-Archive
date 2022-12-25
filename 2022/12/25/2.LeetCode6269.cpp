/*************************************************************************
	> File Name: 2.LeetCode6269.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月25日 星期日 10时32分13秒
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

int closetTarget(vector<string>& words, string target, int startIndex) {
  unordered_set<string> st(words.begin(), words.end());
  if (!st.count(target))
    return -1;
  int n = words.size();
  int ind = startIndex;
  int ans = INT32_MAX;
  int step = 0;
  while (words[ind] != target) {
    ind = (ind + 1) % n;
    step++;
  }
  ans = min(ans, step);
  step = 0;
  ind = startIndex;
  while (words[ind] != target) {
    ind = (ind - 1 + n) % n;
    step++;
  }
  ans = min(ans, step);
  return ans;
}

int main() {
  return 0;
}
