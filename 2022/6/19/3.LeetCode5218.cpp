/*************************************************************************
	> File Name: 3.LeetCode5218.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月19日 星期日 10时35分55秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minimumNumbers(int num, int k) {
  int cnt = 0;
  if (k == 0) k = 10;
  while (num) {
    if (num < k) return -1;
    num -= k;
    cnt++;
    if (num % 10 == 0) break;
  }
  return cnt;
}

int main() {
  return 0;
}
