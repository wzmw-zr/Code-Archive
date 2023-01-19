/*************************************************************************
	> File Name: 1.LeetCode1817.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月20日 星期五 02时25分19秒
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

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
  unordered_map<int, unordered_set<int>> mp;
  for (auto && log : logs) {
    int id = log[0], time = log[1];
    if (!mp.count(id))
      mp[id] = unordered_set<int>();
    mp[id].insert(time);
  }
  vector<int> ans(k, 0);
  for (auto && [x, times] : mp) {
    int cnt = times.size();
    ans[cnt - 1]++;
  }
  return ans;
}

int main() {
  return 0;
}
