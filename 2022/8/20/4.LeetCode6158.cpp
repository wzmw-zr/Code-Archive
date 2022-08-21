/*************************************************************************
	> File Name: 4.LeetCode6158.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月20日 星期六 22时44分02秒
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

string shiftingLetters(string s, vector<vector<int>>& shifts) {
  int n = s.size();
  vector<int> diff(n + 10, 0);
  for (auto && shift : shifts) {
    int start = shift[0], end = shift[1], direction = shift[2];
    diff[start] += direction == 1 ? 1 : -1;
    diff[end + 1] -= direction == 1 ? 1 : -1;
  }
  for (int i = 1; i < n; i++)
    diff[i] += diff[i - 1];
  for (int i = 0; i < n; i++) {
    int offset = diff[i] % 26;
    int val = s[i] - 'a';
    val = (val + offset + 26) % 26;
    s[i] = 'a' + val;
  }
  return s;
}

int main() {
  return 0;
}
