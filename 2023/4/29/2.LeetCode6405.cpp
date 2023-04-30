/*************************************************************************
	> File Name: 2.LeetCode6405.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月29日 星期六 22时33分38秒
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

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
  int n = A.size();
  long s1 = 0, s2 = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    s1 |= 1L << A[i];
    s2 |= 1L << B[i];
    ans.push_back(__builtin_popcountl(s1 & s2));
  }
  return ans;
}

int main() {
  return 0;
}
