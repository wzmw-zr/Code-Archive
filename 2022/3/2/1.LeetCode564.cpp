/*************************************************************************
	> File Name: 1.LeetCode564.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月02日 星期三 00时50分45秒
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

// TLE

vector<long> generate() {
  vector<string> ans;
  unordered_map<int, vector<string>> mp;
  mp[0] = vector<string>();
  for (int i = 0; i <= 9; i++) ans.push_back(to_string(i));
  mp[1] = ans;

  for (int i = 2; i <= 18; i++) {
    vector<string> temp;
    for (int j = 1; j <= 9; j++) {
      for (string s : mp[i - 2]) {
        string t = to_string(j) + s + to_string(j);
        temp.push_back(t);
        ans.push_back(t);
      }
    }
    mp[i] = temp;
  }

  vector<long> res;
  for (auto &&s : ans) res.push_back(stol(s));
  sort(res.begin(), res.end());
  return res;
}

int find_last_le(vector<long> &nums, long t) {
  int l = 0, r = nums.size() - 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (nums[mid] <= t) l = mid;
    else r = mid - 1;
  }
  return l;
}

int find_first_ge(vector<long> &nums, long t) {
  int l = 0, r = nums.size() - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (nums[mid] >= t) r = mid;
    else l = mid + 1;
  }
  return l;
}

string nearestPalindromic(string n) {
  vector<long> nums = generate();
  cout << nums.size() << endl;
  long t = stol(n);
  int last_le = find_last_le(nums, t);
  int first_ge = find_first_ge(nums, t);
  if (abs(nums[last_le] - t) <= abs(nums[first_ge] - t)) return to_string(nums[last_le]);
  return to_string(nums[first_ge]);
}

int main() {
  string n;
  cin >> n;
  cout << nearestPalindromic(n) << endl;
  return 0;
}
