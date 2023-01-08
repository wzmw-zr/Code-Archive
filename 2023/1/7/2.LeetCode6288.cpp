/*************************************************************************
	> File Name: 2.LeetCode6288.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月07日 星期六 22时35分48秒
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

class DataStream {
public:
  deque<int> que;
  unordered_map<int, int> mp;
  int value, k;

  DataStream(int value, int k) : que(deque<int>()), mp(unordered_map<int, int>()), value(value), k(k) {}

  bool consec(int num) {
    if (que.size() == k) {
      if (!(--mp[que.front()]))
        mp.erase(que.front());
      que.pop_front();
    }
    que.push_back(num);
    mp[num]++;
    return que.size() == k && mp.size() == 1 && que.front() == value;
  }
};

int main() {
  return 0;
}
