/*************************************************************************
	> File Name: 1.LeetCode1487.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月03日 星期五 09时38分56秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<string> getFolderNames(vector<string>& names) {
  unordered_map<string, int> mp;
  vector<string> ans;
  function<string(string)> update = [&](string name) -> string {
    string res;
    if (!mp.count(name)) {
      mp[name] = 0;
      res = name;
    } else {
      int id = mp[name] + 1;
      while (mp.count(name + "(" + to_string(id) + ")"))
        id++;
      mp[name] = id;
      res = name + "(" + to_string(id) + ")";
      mp[res] = 0;
    }
    return res;
  };
  for (auto && name : names)
    ans.push_back(update(name));
  return ans;
}

int main() {
  return 0;
}
