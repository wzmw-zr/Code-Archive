/*************************************************************************
	> File Name: 1.LeetCode2379.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月09日 星期四 09时14分03秒
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

int minimumRecolors(string blocks, int k) {
  int n = blocks.size();
  int cnt = 0;
  int ind = 0;
  while (ind < k) {
    cnt += blocks[ind] == 'W' ? 1 : 0;
    ind++;
  }
  int ans = cnt;
  while (ind < n) {
    cnt += blocks[ind] == 'W' ? 1 : 0;
    cnt -= blocks[ind - k] == 'W' ? 1 : 0;
    ind++;
    ans = min(ans, cnt);
  }
  return ans;
}

int main() {
  return 0;
}
