/*************************************************************************
	> File Name: 3.LeetCode6431.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月14日 星期日 10时36分00秒
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

bool doesValidArrayExist(vector<int>& derived) {
  int n = derived.size();
  vector<int> original = {0};
  for (int i = 0; i < n - 1; i++) {
    int val = derived[i] ^ original[i];
    original.push_back(val);
  }
  if ((original[n - 1] ^ original[0]) == derived[n - 1])
    return true;

  original = {1};
  for (int i = 0; i < n - 1; i++) {
    int val = derived[i] ^ original[i];
    original.push_back(val);
  }
  if ((original[n - 1] ^ original[0]) == derived[n - 1])
    return true;
  return false;
}

int main() {
  return 0;
}
