/*************************************************************************
	> File Name: 3.LeetCode6208.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月15日 星期六 22时30分52秒
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

void dfs(string &hour, vector<string> &hours, int ind) {
  if (ind == 2) {
    hours.push_back(hour);
    return ;
  }
  if (hour[ind] == '?') {
    for (int i = 0; i <= 9; i++) {
      hour[ind] = '0' + i;
      dfs(hour, hours, ind + 1);
      hour[ind] = '?';
    }
  } else {
    dfs(hour, hours, ind + 1);
  }
}

int countTime(string time) {
  string hour = time.substr(0, 2);
  string minute = time.substr(3, 2);
  vector<string> hours;
  vector<string> minutes;
  dfs(hour, hours, 0);
  dfs(minute, minutes, 0);
  int cnt_1 = 0, cnt_2 = 0;
  for (auto && x : hours) {
    if (stoi(x) >= 0 && stoi(x) <= 23)
      cnt_1++;
  }
  for (auto && x : minutes) {
    if (stoi(x) >= 0 && stoi(x) <= 59)
      cnt_2++;
  }
  return cnt_1 * cnt_2;
}

int main() {
  return 0;
}
