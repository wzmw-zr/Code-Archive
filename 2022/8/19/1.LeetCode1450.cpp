/*************************************************************************
	> File Name: 1.LeetCode1450.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月19日 星期五 09时09分38秒
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

const int len = 1010;
int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
  int n = startTime.size();
  vector<int> vals(len, 0);
  for (int i = 0; i < n; i++) {
    vals[startTime[i]]++;
    vals[endTime[i] + 1]--;
  }
  for (int i = 1; i <= 1000; i++) 
    vals[i] = vals[i] + vals[i - 1];
  return vals[queryTime];
}

int main() {
  return 0;
}
