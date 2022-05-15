/*************************************************************************
	> File Name: 2.LeetCode6064.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月15日 星期日 10时41分52秒
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

int maxConsecutive(int bottom, int top, vector<int>& special) {
  sort(special.begin(), special.end());
  int n = special.size();
  int mmax = max(special[0] - bottom, top - special[n - 1]);
  for (int i = 0; i < n - 1; i++) {
    mmax = max(mmax, special[i + 1] - special[i] - 1);
  }
  return mmax;
}

int main() {
  return 0;
}
