/*************************************************************************
	> File Name: 1.LeetCode2409.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月17日 星期一 09时23分05秒
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

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
  int month;
  int day;

  Date() = default;
  Date(int month, int day) : month(month), day(day) {}
  Date(string s) : month(stoi(s.substr(0, 2))), day(stoi(s.substr(3))) {}

  bool operator<(const struct Date &that) const {
    return this->month == that.month ? this->day < that.day : this->month < that.month;
  }

  int operator-(const struct Date &that) const {
    int ans = this->day + (this->month == that.month ? 0 : months[that.month]) - that.day + 1;
    for (int i = that.month + 1; i < this->month; i++)
      ans += months[i];
    return ans;
  }
};

int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
  Date a1(arriveAlice), a2(leaveAlice), b1(arriveBob), b2(leaveBob);
  if (a2 < b1 || b2 < a1)
    return 0;
  return min(a2, b2) - max(a1, b1);
}

int main() {
  return 0;
}
