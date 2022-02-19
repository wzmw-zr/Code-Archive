/*************************************************************************
	> File Name: 1.LeetCode717.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月20日 星期日 00时13分47秒
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

bool isOneBitCharacter(vector<int>& bits) {
  int n = bits.size();
  if (bits[n - 1] == 1) 
    return false;
  for (int i = 0; i < n - 1; ) {
    if (bits[i] == 0) 
      i++;
    else {
      if (i == n - 2) 
        return false;
      i += 2;
    }
  }
  return true;
}

int main() {
  return 0;
}
