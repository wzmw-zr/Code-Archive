/*************************************************************************
	> File Name: 3.LeetCode6012.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月20日 星期日 10时30分59秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int countEven(int num) {
  auto calculate = [](int x) {
    int sum = 0;
    while (x) {
      sum += x % 10;
      x /= 10;
    }
    return sum;
  };
  int ans = 0;
  for (int i = 2; i <= num; i++) {
    if (calculate(i) & 1) 
      continue;
    ans++;
  }
  return ans;
}

int main() {
  return 0;
}
