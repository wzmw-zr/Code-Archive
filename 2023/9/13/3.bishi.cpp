/*************************************************************************
	> File Name: 3.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月13日 星期三 21时02分01秒
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

struct UnionSet {
  vector<int> fa;
  vector<int> size;

  UnionSet(int n) : fa(vector<int>(n + 1)), size(vector<int>(n + 1, 1)) {
    for (int i = 0; i <= n; i++)
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
    size[b] += size[a];
  }
};

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  UnionSet u(n);
  int x, y;
  while (m--) {
    cin >> x >> y;
    u.merge(x, y);
  }
  int a = u.get(s);
  int b = u.get(t);
  cout << (a == b ? u.size[a] : 1L * u.size[a] * u.size[b]) << endl;
  return 0;
}
