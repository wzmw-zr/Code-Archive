/*************************************************************************
	> File Name: 4.LeetCode5998.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月19日 星期六 22时39分39秒
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

vector<long long> maximumEvenSplit(long long finalSum) {
  if (finalSum & 1) 
    return {};
  long long num = 2;
  vector<long long> ans;
  while (1) {
    if (num * 2 >= finalSum) {
      ans.push_back(finalSum);
      break;
    }
    ans.push_back(num);
    finalSum -= num;
    num += 2;
  }
  return ans;
}

int main() {
  return 0;
}
