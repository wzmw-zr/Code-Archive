/*************************************************************************
	> File Name: 2.LeetCode6200.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月09日 星期日 10时31分47秒
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

int hardestWorker(int n, vector<vector<int>>& logs) {
  int pre = 0;
  for (auto && log : logs) {
    int temp = log[1];
    log[1] -= pre;
    pre = temp;
  }
  sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b) {
    return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
  });
  return (*logs.rbegin())[0];
}

int main() {
  return 0;
}
