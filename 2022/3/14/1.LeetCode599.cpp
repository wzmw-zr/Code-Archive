/*************************************************************************
	> File Name: 1.LeetCode599.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月14日 星期一 10时18分47秒
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

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
  unordered_map<string, int> mp1, mp2;
  for (int i = 0; i < list1.size(); i++) mp1[list1[i]] = i;
  for (int i = 0; i < list2.size(); i++) mp2[list2[i]] = i;
  map<int, vector<string>> mp;
  for (int i = 0; i < list1.size(); i++) {
    if (!mp2.count(list1[i])) continue;
    int t = i + mp2[list1[i]];
    if (!mp.count(t)) mp[t] = vector<string>(0);
    mp[t].push_back(list1[i]);
  }
  return mp.begin()->second;
}

int main() {
  return 0;
}
