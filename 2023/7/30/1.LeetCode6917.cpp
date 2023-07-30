/*************************************************************************
	> File Name: 1.LeetCode6917.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月30日 星期日 10时38分02秒
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

int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
  int cnt = 0;
  for (int x : hours)
    cnt += x >= target ? 1 : 0;
  return cnt;
}

int main() {
  return 0;
}
