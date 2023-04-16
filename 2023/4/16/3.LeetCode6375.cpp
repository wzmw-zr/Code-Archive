/*************************************************************************
	> File Name: 3.LeetCode6375.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月16日 星期日 10时38分44秒
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

int addMinimum(string word) {
  int n = word.size();
  int ind = 0;
  int ans = 0;
  while (word[ind]) {
    if (word[ind] == 'a') {
      if (ind + 1 == n || word[ind + 1] == 'a') {
        ans += 2;
        ind++;
      } else if (word[ind + 1] == 'c'){
        ans += 1;
        ind += 2;
      } else if (word[ind + 1] == 'b') {
        if (ind + 2 == n || word[ind + 2] != 'c') {
          ans += 1;
          ind += 2;
        } else {
          ind += 3;
        }
      }
    } else if (word[ind] == 'b') {
      if (ind + 1 == n || word[ind + 1] != 'c') {
        ans += 2;
        ind++;
      } else {
        ans += 1;
        ind += 2;
      }
    } else if (word[ind] == 'c') {
      ans += 2;
      ind++;
    }
  }
  return ans;
}

int main() {
  return 0;
}
