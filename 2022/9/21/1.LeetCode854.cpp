/*************************************************************************
	> File Name: 1.LeetCode854.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月21日 星期三 09时22分46秒
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

// WA
int kSimilarity(string s1, string s2) {
  int n = s1.size();
  int ind = 0;
  int ans = 0;
  while (s1[ind]) {
    unordered_map<char, int> mp1, mp2;
    int left = ind;
    do {
      mp1[s1[ind]]++;
      mp2[s2[ind]]++;
      ind++;
    } while (s1[ind] && mp1 != mp2);
    string t1 = s1.substr(left, ind - left);
    string t2 = s2.substr(left, ind - left);
    if (t1 == t2) 
      continue;
    int diff = 0;
    for (int i = 0; t1[i]; i++) 
      diff += t1[i] == t2[i] ? 0 : 1;
    ans += diff - 1;
  }
  return ans;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << kSimilarity(s1, s2) << endl;
  return 0;
}
