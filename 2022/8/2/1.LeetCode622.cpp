/*************************************************************************
	> File Name: 1.LeetCode622.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月02日 星期二 09时23分05秒
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

class MyCircularQueue {
public:
  vector<int> nums;
  int total_len;
  int len;
  int head;

  MyCircularQueue(int k) : nums(vector<int>(k, 0)), total_len(k), len(0), head(0) {}

  bool enQueue(int value) {
    if (len == total_len) return false;
    int ind = (head + len) % total_len;
    nums[ind] = value;
    len++;
    return true;
  }

  bool deQueue() {
    if (len == 0) return false;
    head = (head + 1) % total_len;
    len--;
    return true;
  }

  int Front() {
    if (len == 0) return -1;
    return nums[head];
  }

  int Rear() {
    if (len == 0) return -1;
    return nums[(head + len - 1) % total_len];
  }

  bool isEmpty() {
    return len == 0;
  }

  bool isFull() {
    return len == total_len;
  }
};

int main() {
  return 0;
}
