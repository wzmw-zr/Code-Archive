/*************************************************************************
	> File Name: 1.LeetCode1017.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月06日 星期四 09时28分17秒
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

string baseNeg2(int n) {
  int p = 0;
  int val = 0;
  while (val <= n) {
    val += 1 << p;
    p += 2;
  }
  int dis = val - n;
  int ind = 0;
  while (dis) {
    if (dis & (1 << ind)) {
      if (ind & 1) {
        val += 1 << ind;
      } else {
        val -= 1 << ind;
      }
      dis -= 1 << ind;
    }
    ind++;
  }
  string ans = "";
  do {
    ans += '0' + (val & 1);
    val >>= 1;
  } while (val);
  reverse(ans.begin(), ans.end());
  return ans;
}


int main() {
  int n;
  cin >> n;
  cout << baseNeg2(n) << endl;
  return 0;
}
