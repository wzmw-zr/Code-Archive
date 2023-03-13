/*************************************************************************
	> File Name: 2.LeetCode2589.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月13日 星期一 10时43分01秒
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

int findMinimumTime(vector<vector<int>>& tasks) {
  int n = tasks.size();
  vector<int> vals(2010, 0);
  sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b){
    return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
  });
  int sum = 0;
  for (auto && task : tasks) {
    int left = task[0], right = task[1], duration = task[2];
    int inter = 0;
    for (int i = left; i <= right; i++)
      inter += vals[i];
    duration = max(0, duration - inter);
    sum += duration;
    for (int i = right; i >= left && duration; i--) {
      duration -= vals[i] ? 0 : 1;
      vals[i] = 1;
    }
  }
  return sum;
}

int main() {
  return 0;
}
