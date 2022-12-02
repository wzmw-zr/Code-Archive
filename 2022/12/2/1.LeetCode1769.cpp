/*************************************************************************
	> File Name: 1.LeetCode1769.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月02日 星期五 09时35分03秒
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

vector<int> minOperations(string boxes) {
  int n = boxes.size();
  vector<int> pre(n + 1, 0);
  vector<int> suf(n + 1, 0);
  int pre_cnt = 0;
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + pre_cnt;
    pre_cnt += boxes[i] == '1' ? 1 : 0;
  }
  int suf_cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + suf_cnt;
    suf_cnt += boxes[i] == '1' ? 1 : 0;
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
    ans[i] = pre[i + 1] + suf[i];
  return ans;
}

int main() {
  return 0;
}
