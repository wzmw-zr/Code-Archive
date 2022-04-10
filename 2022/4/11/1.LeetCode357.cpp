/*************************************************************************
	> File Name: 1.LeetCode357.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月11日 星期一 00时37分33秒
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

int countNumbersWithUniqueDigits(int n) {
  auto calculate = [](int x) -> int {
    if (x == 0) return 1;
    if (x == 1) return 9;
    int ans = 9;
    for (int i = 1; i < x; i++) ans *= 10 - i;
    return ans;
  };
  int ans = 0;
  for (int i = 0; i <= n; i++) ans += calculate(i);
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << countNumbersWithUniqueDigits(n) << endl;
  return 0;
}
