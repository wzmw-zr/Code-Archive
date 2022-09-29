/*************************************************************************
	> File Name: 1.LeetCode2691.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月29日 星期四 09时05分37秒
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

bool isFlipedString(string s1, string s2) {
  if (s1.size() != s2.size())
    return false;
  return (s1 + s1).find(s2) != std::string::npos;
}

int main() {
  return 0;
}
