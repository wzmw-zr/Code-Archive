/*************************************************************************
	> File Name: 4.LeetCode6129.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月16日 星期日 10时35分54秒
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

bool sumOfNumberAndReverse(int num) {
  auto reverse_num = [&](int x) -> int {
    string t = to_string(x);
    reverse(t.begin(), t.end());
    return stoi(t);
  };
  for (int i = 0; i <= num; i++) {
    if (i + reverse_num(i) == num)
      return true;
  }
  return false;
}

int main() {
  return 0;
}
