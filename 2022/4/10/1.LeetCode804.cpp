/*************************************************************************
	> File Name: 1.LeetCode804.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月10日 星期日 00时11分13秒
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

int uniqueMorseRepresentations(vector<string>& words) {
  vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
  unordered_set<string> st;
  auto change = [&](string &s) ->string {
    string ans = "";
    for (char c : s) ans += codes[c - 'a'];
    return ans;
  };
  for (string &word : words) st.insert(change(word));
  return st.size();
}

int main() {
  return 0;
}
