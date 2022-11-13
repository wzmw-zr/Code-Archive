/*************************************************************************
	> File Name: 1.LeetCode791.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月13日 星期日 09时45分10秒
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

string customSortString(string order, string s) {
  unordered_map<char, int> mp;
  for (int i = 0; order[i]; i++)
    mp[order[i]] = i;
  sort(s.begin(), s.end(), [&](char a, char b){
    return mp[a] < mp[b];
  });
  return s;
}

int main() {
  return 0;
}
