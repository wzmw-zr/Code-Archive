/*************************************************************************
	> File Name: 1.LeetCode1656.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月16日 星期二 09时06分16秒
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

class OrderedStream {
public:
  unordered_map<int, string> mp;
  int n;
  int ptr;
  OrderedStream(int n) : n(n), ptr(1) {}

  vector<string> insert(int idKey, string value) {
    mp[idKey] = value;
    vector<string> ans;
    if (ptr == idKey) {
      while (mp.count(ptr + 1)) {
        ans.push_back(mp[ptr]);
        ptr++;
      }
      ans.push_back(mp[ptr]);
      ptr++;
    }
    return ans;
  }
};


int main() {
  return 0;
}
