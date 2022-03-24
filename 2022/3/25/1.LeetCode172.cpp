/*************************************************************************
	> File Name: 1.LeetCode172.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月25日 星期五 00时37分00秒
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

int trailingZeroes(int n) {
  int two = 0, five = 0;
  for (int i = 1; i <= n; i++) {
    int t = i;
    while (t % 2 == 0) {
      two++;
      t /= 2;
    }
    while (t % 5 == 0) {
      five++;
      t /= 5;
    }
  }
  return min(two, five);
}

int main() {
  return 0;
}
