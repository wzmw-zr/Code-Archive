/*************************************************************************
	> File Name: 2.LeetCode6921.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月23日 星期日 10时33分01秒
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

vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
  vector<string> ans;
  for (auto && word : words) {
    int l = 0, r = 0;
    while (word[r]) {
      while (word[r] && word[r] == separator)
        l++, r++;
      string s = "";
      while (word[r] && word[r] != separator)
        s += word[r++];
      if (s.size())
        ans.push_back(s);
      l = r;
    }
  }
  return ans;
}

int main() {
  return 0;
}
