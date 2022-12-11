/*************************************************************************
	> File Name: 4.LeetCode6259.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月11日 星期日 15时11分39秒
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

class Allocator {
public:
  int n;
  vector<int> mems;

  Allocator(int n) : n(n), mems(vector<int>(n, -1)) {}

  int allocate(int size, int mID) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (mems[i] == -1)
        cnt++;
      else
        cnt = 0;
      if (cnt == size) {
        for (int j = i - size + 1; j <= i; j++)
          mems[j] = mID;
        return i - size + 1;
      }
    }
    return -1;
  }

  int free(int mID) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (mems[i] == mID) {
        mems[i] = -1;
        cnt++;
      }
    }
    return cnt;
  }
};


int main() {
  return 0;
}
