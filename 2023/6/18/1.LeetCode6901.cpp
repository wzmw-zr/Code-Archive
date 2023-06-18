/*************************************************************************
	> File Name: 1.LeetCode6901.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年06月18日 星期日 10时31分15秒
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

int distanceTraveled(int mainTank, int additionalTank) {
  int ans = 0;
  while (mainTank && additionalTank) {
    if (mainTank < 5)
      return (ans + mainTank) * 10;
    int t = min(additionalTank, mainTank / 5);
    ans += 5 * t;
    mainTank -= 4 * t;
    additionalTank -= t;
  }
  return (ans + mainTank) * 10;
}

int main() {
  return 0;
}
