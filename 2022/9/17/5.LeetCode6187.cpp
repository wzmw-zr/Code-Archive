/*************************************************************************
	> File Name: 5.LeetCode6187.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月17日 星期六 23时11分28秒
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

// WA
long long minimumMoney(vector<vector<int>>& transactions) {
  sort(
    transactions.begin(), 
    transactions.end(), 
    [](vector<int> &a, vector<int> &b) {
      return a[1] < b[1];
    }
  );
  long long init = 0;
  long long current = 0;
  for (auto && x : transactions) {
    if (current < static_cast<long long>(x[0])) {
      init += static_cast<long long>(x[0]) - current;
      current = x[0];
    }
    current = current - x[0] + x[1];
  }
  return init;
}

int main() {
  return 0;
}
