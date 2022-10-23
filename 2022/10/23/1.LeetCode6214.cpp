/*************************************************************************
	> File Name: 1.LeetCode6214.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月23日 星期日 10时32分09秒
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

struct Time {
  int hour;
  int minite;

  Time() = default;
  Time(int hour, int minite) : hour(hour), minite(minite) {}
  Time(string &s) : hour(stoi(s.substr(0, 2))), minite(stoi(s.substr(3, 2))) {}

  bool operator<(const struct Time &that) const {
    return this->hour == that.hour ? this->minite < that.minite : this->hour < that.hour;
  }
};

bool haveConflict(vector<string>& event1, vector<string>& event2) {
  Time t1(event1[0]), t2(event1[1]), t3(event2[0]), t4(event2[1]);
  if (t2 < t3 || t4 < t1)
    return false;
  return true;
}

int main() {
  return 0;
}
