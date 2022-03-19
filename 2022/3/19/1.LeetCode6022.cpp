/*************************************************************************
	> File Name: 1.LeetCode6022.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月19日 星期六 22时33分58秒
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

int halveArray(vector<int>& nums) {
  double sum = 0;
  for (double x : nums) sum += x;
  double temp = sum;
  int step = 0;
  priority_queue<double> que;
  for (double x : nums) que.push(x);
  while (temp > sum / 2) {
    double t = que.top();
    que.pop();
    temp -= t / 2;
    que.push(t / 2);
    step++;
  }
  return step;
}

int main() {
  return 0;
}
