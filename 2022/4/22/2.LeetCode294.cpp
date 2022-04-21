/*************************************************************************
	> File Name: 2.LeetCode294.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月22日 星期五 01时42分16秒
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

// TLE
unordered_map<string, bool> mp;

bool canWin(string currentState) {
  if (mp.count(currentState)) return mp[currentState];
  int n = currentState.size();
  for (int i = 0; i < n - 1; i++) {
    if (currentState[i] == '+' && currentState[i + 1] == '+') {
      currentState[i] = currentState[i + 1] = '-';
      bool res = canWin(currentState);
      currentState[i] = currentState[i + 1] = '+';
      if (!res) return mp[currentState] = true;
    }
  }
  return mp[currentState] = false;
}

int main() {
  string currentState;
  cin >> currentState;
  cout << canWin(currentState) << endl;
  return 0;
}
