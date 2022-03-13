/*************************************************************************
	> File Name: 1.LeetCode393.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月13日 星期日 09时29分38秒
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

int get_len(int num) {
  if ((num >> 7) == 0) return 1;
  int len = 0;
  while (len < 5) {
    if (num & (1 << (7 - len))) len++;
    else break;
  }
  return len >= 2 && len <= 4 ? len : -1;
}

bool validUtf8(vector<int>& data) {
  int n = data.size();
  int ind = 0;
  while (ind < n) {
    int len = get_len(data[ind]);
    if (len == -1) return false;
    if (ind + len > n) return false;
    for (int i = 1; i < len; i++) {
      if ((data[ind + i] >> 6) == 2) continue;
      return false;
    }
    ind += len;
  }
  return true;
}

int main() {
  return 0;
}
