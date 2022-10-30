/*************************************************************************
	> File Name: 3.LeetCode6221.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月30日 星期日 10时33分24秒
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

using PIS = pair<int, string>;

struct User {
  string name;
  vector<PIS> works;
  long sum;

  User() = default;
  User(string name) : name(name), works(vector<PIS>(0)), sum(0) {}
};

vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
  unordered_map<string, User> mp;
  int n = creators.size();
  for (int i = 0; i < n; i++) {
    if (!mp.count(creators[i]))
      mp[creators[i]] = User(creators[i]);
    mp[creators[i]].works.push_back(PIS(views[i] * -1, ids[i]));
    mp[creators[i]].sum += views[i];
  }
  long mmax = 0;
  for (auto && [name, user] : mp) {
    sort(user.works.begin(), user.works.end());
    mmax = max(mmax, user.sum);
  }
  vector<vector<string>> ans;
  for (auto && [name, user] : mp) {
    if (user.sum == mmax) 
      ans.push_back({name, user.works[0].second});
  }
  return ans;
}

int main() {
  return 0;
}
