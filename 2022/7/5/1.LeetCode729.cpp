/*************************************************************************
	> File Name: 1.LeetCode729.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月05日 星期二 09时00分59秒
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

using PII = pair<int, int>;

class MyCalendar {
public:
  vector<PII> intervals;

  MyCalendar() {}

  bool book(int start, int end) {
    for (auto && inter : intervals) {
      if (inter.second > start && inter.first < end) 
        return false;
    }
    intervals.push_back(PII(start, end));
    return true;
  }
};

int main() {
  return 0;
}
