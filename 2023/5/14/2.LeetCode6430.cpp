/*************************************************************************
	> File Name: 2.LeetCode6430.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月14日 星期日 10时30分57秒
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

vector<int> circularGameLosers(int n, int k) {
  unordered_set<int> st;
  int id = 0, round = 1;
  while (!st.count(id)) {
    st.insert(id);
    id = (id + round * k) % n;
    round++;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (!st.count(i))
      ans.push_back(i + 1);
  }
  return ans;
}

int main() {
  return 0;
}
