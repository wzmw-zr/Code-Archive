/*************************************************************************
	> File Name: 1.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月15日 星期六 20时24分13秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using PLL = pair<long, long>;

unordered_set<int> st;

pair<vector<PLL>, bool> dfs(long x) {
  if (x == 0) {
    return {{}, true};
  }
  long p = 0;
  long val = 1;
  while (val <= x) {
    val *= 3;
    p++;
  }
  val /= 3;
  if (!st.count(val)) {
    st.insert(val);
    auto [path, ok] = dfs(x - val);
    if (ok) {
      path.push_back(PLL(1, val));
      st.erase(val);
      return {path, ok};
    }
    st.erase(val);
  }
  if (!st.count(val * 3)) {
    st.insert(val * 3);
    auto [path, ok] = dfs(val * 3 - x);
    if (ok) {
      for (auto && x : path)
        x.first *= -1;
      path.push_back(PLL(1, val * 3));
      st.erase(val * 3);
      return {path, ok};
    }
    st.erase(val * 3);
  }
  return {{}, false};
}


int main() {
  long x;
  cin >> x;
  auto [path, ok] = dfs(x);
  reverse(path.begin(), path.end());
  int n = path.size();
  string ans = "";
  for (int i = 0; i < n; i++) {
    if (path[i].first == 1) {
      ans += (i == 0 ? "" : "+") + to_string(path[i].second);
    } else {
      ans += "-" + to_string(path[i].second);
    }
  }
  cout << ans << endl;
  return 0;
}
