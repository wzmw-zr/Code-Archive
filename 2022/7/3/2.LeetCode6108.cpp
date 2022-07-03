/*************************************************************************
	> File Name: 2.LeetCode6108.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月03日 星期日 10时35分44秒
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

string decodeMessage(string key, string message) {
  unordered_set<char> st;
  unordered_map<char, char> mp;
  int ind = 0;
  for (char c : key) {
    if (c == ' ') continue;
    if (st.count(c)) continue;
    st.insert(c);
    mp[c] = ind + 'a';
    ind++;
  }
  for (int i = 0; message[i]; i++) {
    if (message[i] == ' ') continue;
    message[i] = mp[message[i]]; 
  }
  return message;
}

int main() {
  return 0;
}
