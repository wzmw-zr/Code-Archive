/*************************************************************************
	> File Name: 2.LeetCode6323.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月18日 星期六 22时33分40秒
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

int distMoney(int money, int children) {
  if (money < children)
    return -1;
  money -= children;
  int x = money / 7;
  int y = money % 7;
  if (x > children)
    return children - 1;
  if (x == children)
    return y == 0 ? children : children - 1;
  int rest = children - x;
  if (rest == 1) {
    if (y == 3)
      return x - 1;
    return x;
  }
  return x;
}

int main() {
  return 0;
}
