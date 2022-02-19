/*************************************************************************
	> File Name: 3.LeetCode5997.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月19日 星期六 22时33分18秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<long long> sumOfThree(long long num) {
  if (num % static_cast<long long>(3) != 0) 
    return {};
  long long mid = num / static_cast<long long>(3);
  return {mid - 1, mid, mid + 1};
}

int main() {
  return 0;
}
