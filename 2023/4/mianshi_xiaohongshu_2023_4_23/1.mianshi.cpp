/*************************************************************************
	> File Name: 1.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月23日 星期日 16时52分16秒
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

long MOD = 1e9 + 7;

unordered_map<int, long> mp;

long dfs(int x) {
  if (x == 0)
    return 1;
  if (mp.count(x))
    return mp[x];
  return mp[x] = (1 + 1L * (x + 1) * dfs(x - 1)) % MOD;
}

long NumberOfOps(vector<int> &nums) {
  long ans = 0;
  for (int x : nums)
    ans = (ans + dfs(x)) % MOD;
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << NumberOfOps(nums) << endl;
  return 0;
}
