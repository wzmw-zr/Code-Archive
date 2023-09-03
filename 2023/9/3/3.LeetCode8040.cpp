/*************************************************************************
	> File Name: 3.LeetCode8040.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月03日 星期日 11时14分16秒
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

int minimumOperations(string num) {
  int n = num.size();
  int ans = n;
  for (char c : num) {
    if (c == '0')
      ans = n - 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (num[i] == '0') {
      for (int j = i - 1; j >= 0; j--) {
        if (num[j] == '0' || num[j] == '5')
          ans = min(ans, n - j - 2);
      }
    }
    if (num[i] == '5') {
      for (int j = i - 1; j >= 0; j--) {
        if (num[j] == '2' || num[j] == '7')
          ans = min(ans, n - j - 2);
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
