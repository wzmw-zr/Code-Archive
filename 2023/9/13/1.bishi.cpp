/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月13日 星期三 20时50分36秒
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

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  unordered_set<int> st;
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (st.count(nums[i]))
      continue;
    st.insert(nums[i]);
    ans.push_back(nums[i]);
  }
  for (int i = static_cast<int>(ans.size()) - 1; i >= 0; i--)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
