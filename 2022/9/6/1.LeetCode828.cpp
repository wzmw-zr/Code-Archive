/*************************************************************************
	> File Name: 1.LeetCode828.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月06日 星期二 09时43分16秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int uniqueLetterString(string s) {
  int n = s.size();
  vector<vector<int>> inds(26, vector<int>(0));
  for (int i = 0; i < n; i++) {
    int ind = s[i] - 'A';
    inds[ind].push_back(i);
  }
  int ans = 0;
  for (auto && ind_vec : inds) {
    int pre = -1, suf = n;
    int m = ind_vec.size();
    vector<int> temp;
    temp.push_back(-1);
    for (int i = 0; i < m; i++)
      temp.push_back(ind_vec[i]);
    temp.push_back(n);
    for (int i = 1; i <= m; i++) 
      ans += (temp[i] - temp[i - 1]) * (temp[i + 1] - temp[i]);
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << uniqueLetterString(s) << endl;
  return 0;
}
