/*************************************************************************
	> File Name: 1.LeetCode831.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月01日 星期六 09时32分48秒
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

string maskPII(string s) {
  string ans;
  if (s.find('@') == std::string::npos) {
    string nums = "";
    for (int i = 0; s[i]; i++) {
      if (s[i] >= '0' && s[i] <= '9')
        nums += s[i];
    }
    string nation = "";
    for (int i = 0; i < nums.size() - 10; i++)
      nation += '*';
    string t = "***-***-" + nums.substr(nums.size() - 4);
    ans = (nation.size() ? "+" : "") + nation + (nation.size() ? "-" : "") + t;
  } else {
    int n = s.find('@');
    string person = s.substr(0, n);
    string domain = s.substr(n + 1);
    for (int i = 0; person[i]; i++) {
      if (person[i] >= 'A' && person[i] <= 'Z')
        person[i] += 32;
    }
    for (int i = 0; domain[i]; i++) {
      if (domain[i] >= 'A' && domain[i] <= 'Z')
        domain[i] += 32;
    }
    string t = "*****";
    t = *person.begin() + t + *person.rbegin();
    ans = t + "@" + domain;
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << maskPII(s) << endl;
  return 0;
}
