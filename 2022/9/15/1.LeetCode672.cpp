/*************************************************************************
	> File Name: 1.LeetCode672.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月15日 星期四 19时45分24秒
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

int flipLights(int n, int presses) {
  unordered_set<int> states({0xf});
  vector<int> masks({0xf, 0xa, 0x5, 0x9});
  for (int i = 0; i < presses; i++) {
    unordered_set<int> st;
    for (int x : states) {
      for (int mask : masks) 
        st.insert(x ^ mask);
    }
    states = st;
  }
  n = min(n, 4);
  unordered_set<int> st;
  for (int x : states) 
    st.insert(x & ((1 << n) - 1));
  return static_cast<int>(st.size());
}

int main() {
  int n, presses;
  cin >> n >> presses;
  cout << flipLights(n, presses) << endl;
  return 0;
}
