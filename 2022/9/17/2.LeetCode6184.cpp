/*************************************************************************
	> File Name: 2.LeetCode6184.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月17日 星期六 22时31分21秒
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

vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
  int m1 = stoi(arriveAlice.substr(0, 2)), d1 = stoi(arriveAlice.substr(3, 2));
  int m2 = stoi(leaveAlice.substr(0, 2)), d2 = stoi(leaveAlice.substr(3, 2));
  int m3 = stoi(arriveBob.substr(0, 2)), d3 = stoi(arriveBob.substr(3, 2));
  int m4 = stoi(leaveBob.substr(0, 2)), d4 = stoi(leaveBob.substr(3, 2));
  set<PII> st1, st2;
  for (int i = m1; i <= m2; i++) {
    int start = 1, end = month[i];
    if (i == m1)
      start = d1;
    if (i == m2)
      end = d2;
    for (int j = start; j <= end; j++)
      st1.insert(PII(i, j));
  }
  for (int i = m3; i <= m4; i++) {
    int start = 1, end = month[i];
    if (i == m3)
      start = d3;
    if (i == m4)
      end = d4;
    for (int j = start; j <= end; j++)
      st2.insert(PII(i, j));
  }
  int cnt = 0;
  for (auto && x : st1) {
    if (st2.count(x))
      cnt++;
  }
  return cnt;
}

int main() {
  return 0;
}
