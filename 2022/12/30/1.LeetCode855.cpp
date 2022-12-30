/*************************************************************************
	> File Name: 1.LeetCode855.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月30日 星期五 10时34分16秒
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

class ExamRoom {
public:
  set<int> st;
  int n;
  ExamRoom(int n) : st(set<int>()), n(n) {}

  int seat() {
    if (st.size() == 0) {
      st.insert(0);
      return 0;
    }
    if (st.size() == 1) {
      int x = *st.begin();
      if (x >= (n - 1 - x)) {
        st.insert(0);
        return 0;
      }
      st.insert(n - 1);
      return n - 1;
    }
    int x = *st.begin(), y = *st.rbegin();
    int pos = -1, dis = -1;
    if (x != 0) {
      pos = 0;
      dis = x;
    }
    for (auto iter = st.begin(); iter != st.end() && next(iter) != st.end(); iter++) {
      int a = *next(iter) - *iter - 1;
      if (a == 0)
        continue;
      int t = (a + 1) / 2;
      if (t > dis) {
        dis = t;
        pos = *iter + t;
      }
    }
    if ((y != n - 1) && (n - 1 - y > dis)) {
      pos = n - 1;
      dis = n - 1 - y;
    }
    st.insert(pos);
    return pos;
  }

  void leave(int p) {
    st.erase(p);
  }
};

int main() {
  return 0;
}
