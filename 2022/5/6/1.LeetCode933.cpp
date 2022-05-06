/*************************************************************************
	> File Name: 1.LeetCode933.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月06日 星期五 08时59分55秒
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

class RecentCounter {
public:
  queue<int> que;

  RecentCounter() {}

  int ping(int t) {
    que.push(t);
    while (!que.empty() && que.front() < t - 3000) que.pop();
    return static_cast<int>(que.size());
  }
};

int main() {
  return 0;
}
