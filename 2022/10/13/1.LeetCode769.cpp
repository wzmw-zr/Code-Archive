/*************************************************************************
	> File Name: 1.LeetCode769.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月13日 星期四 09时41分35秒
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

int maxChunksToSorted(vector<int>& arr) {
  int n = arr.size();
  int ind = 0, ans = 0;
  while (ind < n) {
    set<int> st1, st2;
    do {
      st1.insert(ind);
      st2.insert(arr[ind]);
      ind++;
    } while (ind < n && st1 != st2);
    ans++;
  }
  return ans;
}

int main() {
  return 0;
}
