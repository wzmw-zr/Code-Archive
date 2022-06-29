/*************************************************************************
	> File Name: 1.LeetCode535.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月29日 星期三 09时03分34秒
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

class Solution {
public:
  int ind;
  unordered_map<int, string> idx_to_url;
  unordered_map<string, int> url_to_idx;

  Solution() : ind(0), idx_to_url(unordered_map<int, string>()), url_to_idx(unordered_map<string, int>()) {}

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    string prefix = "http://tinyurl.com/";
    if (url_to_idx.count(longUrl)) {
      prefix += to_string(url_to_idx[longUrl]);
    } else {
      url_to_idx[longUrl] = ind;
      idx_to_url[ind] = longUrl;
      prefix += to_string(ind);
      ind++;
    }
    return prefix;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string key = "";
    for (int i = static_cast<int>(shortUrl.size()) - 1; i >= 0 && shortUrl[i] != '/'; i--) key += shortUrl[i];
    int idx = stoi(key);
    return idx_to_url[idx];
  }
};

int main() {
  return 0;
}
