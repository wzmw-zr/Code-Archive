/*************************************************************************
	> File Name: 2.LeetCode6055.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月03日 星期日 10时30分42秒
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
  int minute;
  
  Time() = default;
  Time(string s) : hour(stoi(s.substr(0, 2))), minute(stoi(s.substr(3, 2))) {}

  int operator-(const struct Time &that) const {
    if (that <= *this) 
      return 60 * (this->hour - that.hour) + (this->minute - that.minute);
    return 1440 - (that - *this);
  }

  bool operator<=(const struct Time &that) const {
    return this->hour == that.hour ? this->minute <= that.minute : this->hour < that.hour;
  }

};

int convertTime(string current, string correct) {
  Time t1(current), t2(correct);
  cout << t1.hour << " " << t1.minute << endl;
  cout << t2.hour << " " << t2.minute << endl;
  int dis = t2 - t1;
  int ops = 0;
  ops += dis / 60;
  dis -= (dis / 60) * 60;
  ops += dis / 15;
  dis -= (dis / 15) * 15;
  ops += dis / 5;
  dis -= (dis / 5) * 5;
  ops += dis;
  return ops;
}

int main() {
  return 0;
}
