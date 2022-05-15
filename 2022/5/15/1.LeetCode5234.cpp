/*************************************************************************
	> File Name: 1.LeetCode5234.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月15日 星期日 10时34分46秒
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

vector<string> removeAnagrams(vector<string>& words) {
  vector<string> ans;
  int n = words.size();
  int l = 0, r = 1;
  while (r < n) {
    string x = words[l];
    string y = words[r];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (x != y) {
      ans.push_back(words[l]);
      l = r;
    }
    r++;
  }
  ans.push_back(words[l]);
  return ans;
}

int main() {
  return 0;
}
