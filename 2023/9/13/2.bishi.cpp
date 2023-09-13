/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月13日 星期三 20时54分28秒
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

int main() {
  int n;
  cin >> n;
  vector<int> nums(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> nums[i];
  vector<int> inds;
  function<void(int, int)> dfs = [&](int cnt, int multi) -> void {
    if (cnt == 1) {
      inds.push_back(multi);
      return ;
    }
    for (int i = 1; i <= cnt; i += 2)
      inds.push_back(i * multi);
    dfs(cnt / 2, multi * 2);
  };
  dfs(n, 1);
  for (int ind : inds)
    cout << nums[ind] << " ";
  cout << endl;
  return 0;
}
