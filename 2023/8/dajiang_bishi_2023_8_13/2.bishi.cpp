/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月13日 星期日 19时57分25秒
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

vector<int> split(string &s) {
  int ind = 0;
  vector<int> ans;
  while (s[ind]) {
    string str = "";
    while (s[ind] && s[ind] != ',')
      str += s[ind++];
    if (s[ind])
      ind++;
    ans.push_back(stoi(str));
  }
  return ans;
}

bool check(vector<int> &nums, int val1, int val2) {
  int l1 = 0, r1 = nums.size();
  while (l1 < r1) {
    int mid = (l1 + r1) / 2;
    if (nums[mid] <= val1)
      l1 = mid + 1;
    else
      r1 = mid;
  }

  int l2 = 0, r2 = nums.size();
  while (l2 < r2) {
    int mid = (l2 + r2 + 1) / 2;
    if (nums[mid] >= val2) {
      r2 = mid - 1;
    } else {
      l1 = mid;
    }
  }

  return l1 <= l2;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  s1.pop_back();
  s2.pop_back();
  s1 = s1.substr(8);
  s2 = s2.substr(8);
  vector<int> nums1 = split(s1);
  vector<int> nums2 = split(s2);

  sort(nums2.begin(), nums2.end());
  int n = nums1.size();
  vector<int> dp(n, 1);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (nums1[j] < nums1[i])
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  int mmax = 1;
  for (int i = 0; i < n; i++)
    mmax = max(mmax, dp[i]);
  if (n - mmax > nums2.size()) {
    cout << -1 << endl;
  } else {
    unordered_map<int, bool> mp;

    function<bool(int)> dfs = [&](int ind) -> bool {
      if (dp[ind] == 1)
        return true;
      if (mp.count(ind))
        return mp[ind];
      for (int i = ind - 1; i >= 0; i--) {
        if (nums1[i] < nums1[ind] && dp[i] == dp[ind] - 1) {
          if (!check(nums2, nums1[i], nums1[ind]))
            continue;
          if (dfs(i))
            return mp[ind] = true;
        }
      }
      return mp[ind] = false;
    };

    bool ans = false;
    for (int i = n - 1; i >= 0; i--) {
      if (dp[i] == mmax) {
        ans |= dfs(i);
      }
    }
    cout << (ans ? n - mmax : -1) << endl;
  }
  return 0;
}
