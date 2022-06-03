/*************************************************************************
	> File Name: 1.LeetCode829.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月03日 星期五 09时02分25秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int consecutiveNumbersSum(int n) {
  n = n * 2;
  int x = sqrt(n);
  int cnt = 0;
  for (int i = x; i >= 1; i--) {
    if (n % i) continue;
    int j = n / i;
    if (((i + j) & 1) == 0 || ((j - i) & 1) == 0) continue;
    cout << (j - i + 1) / 2 << " " << (i + j - 1) / 2 << endl;
    cnt++;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  cout << consecutiveNumbersSum(n) << endl;
  return 0;
}
