/*************************************************************************
	> File Name: 1.LeetCode811.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月05日 星期三 09时34分04秒
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

vector<string> subdomainVisits(vector<string>& cpdomains) {
  unordered_map<string, int> mp;
  for (string &s : cpdomains) {
    string num = "";
    int n = s.size();
    int ind = 0;
    while (s[ind] && s[ind] != ' ')
      num += s[ind++];
    int val = stoi(num);
    ind = n - 1;
    string str = "";
    while (s[ind] != ' ') {
      while (s[ind] != ' ' && s[ind] != '.')
        str += s[ind--];
      mp[str] += val;
      if (s[ind] == '.') 
        str += s[ind--];
    }
  }
  vector<string> ans;
  for (auto && [str, val] : mp) {
    string s = str;
    reverse(s.begin(), s.end());
    ans.push_back(to_string(val) + " " + s);
  }
  return ans;
}

int main() {
  return 0;
}
