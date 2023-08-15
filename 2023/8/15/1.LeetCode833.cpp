/*************************************************************************
	> File Name: 1.LeetCode833.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月15日 星期二 09时52分30秒
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
#include <tuple>
using namespace std;

using TISS = tuple<int, string, string>;

string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
  int n = s.size(), m = indices.size();
  vector<TISS> vals;
  for (int i = 0; i < m; i++)
    vals.push_back(TISS(indices[i], sources[i], targets[i]));
  sort(vals.begin(), vals.end(), [&](TISS &a, TISS &b){
    auto && [ind_1, source_1, target_1] = a;
    auto && [ind_2, source_2, target_2] = b;
    return ind_1 < ind_2;
  });
  int pre = 0;
  string str = "";
  for (int i = 0; i < m; i++) {
    auto && [ind, source, target] = vals[i];
    str += s.substr(pre, ind - pre);
    pre = ind;
    if (s.substr(ind, source.size()) == source) {
      str += target;
      pre = ind + source.size();
    }
  }
  str += s.substr(pre);
  return str;
}

int main() {
  return 0;
}
