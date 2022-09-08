/*************************************************************************
	> File Name: 1.LeetCode667.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月08日 星期四 09时12分47秒
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

vector<int> constructArray(int n, int k) {
  int left = 1, right = n;
  vector<int> ans;
  if (k & 1) {
    ans.push_back(right--);
    while (k != 1) {
      ans.push_back(left++);
      k--;
      if (k > 1) {
        ans.push_back(right--);
        k--;
      }
    }
    for (int i = right; i >= left; i--)
      ans.push_back(i);
  } else {
    ans.push_back(left++);
    while (k != 1) {
      ans.push_back(right--);
      k--;
      if (k > 1) {
        ans.push_back(left++);
        k--;
      }
    }
    for (int i = right; i >= left; i--)
      ans.push_back(i);
  }
  return ans;
}

int main() {
  int n, k;
  cin >> n >> k;
  auto ans = constructArray(n, k);
  for (int x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
