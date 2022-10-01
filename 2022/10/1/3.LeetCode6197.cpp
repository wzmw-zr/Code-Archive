/*************************************************************************
	> File Name: 3.LeetCode6197.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月01日 星期六 22时43分28秒
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

struct UnionSet {
  int n;
  vector<int> fa;
  vector<int> sizes;

  UnionSet() = default;
  UnionSet(int n) : n(n + 10), fa(vector<int>(n + 10, 0)), sizes(vector<int>(n + 10, 0)) {
    for (int i = 1; i <= n; i++)
      fa[i] = i;
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void merge(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b)
      return ;
    fa[a] = b;
    sizes[b] += sizes[a];
  }

  int query(int x) {
    return sizes[this->get(x)];
  }
};

class LUPrefix {
public:
  UnionSet u;

  LUPrefix(int n) : u(UnionSet(n)) {}

  void upload(int video) {
    u.sizes[video] = 1;
    if (u.sizes[video - 1])
      u.merge(video, video - 1);
    if (u.sizes[video + 1])
      u.merge(video, video + 1);
  }

  int longest() {
    return u.query(1);
  }
};

int main() {
  return 0;
}
