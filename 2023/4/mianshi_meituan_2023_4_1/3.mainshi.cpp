/*************************************************************************
	> File Name: 3.mainshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月01日 星期六 10时27分27秒
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

struct BitTree {
  int n;
  vector<long> vals;

  BitTree() = default;
  BitTree(int n) : n(n), vals(vector<long>(n + 1, 0)) {}

  int lowbit(int x) {
    return x & -x;
  }

  void update(int x, int val) {
    while (x <= n) {
      vals[x] += val;
      x += lowbit(x);
    }
  }

  long query(int x) {
    long ans = 0;
    while (x) {
      ans += vals[x];
      x -= lowbit(x);
    }
    return ans;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  BitTree bit_tree(n + 10);
  vector<int> nums(n + 10, 0);
  int flag = 0;
  vector<int> ops(m), arr_x(m), arr_y(m);
  for (int i = 0; i < m; i++)
    cin >> ops[i];
  for (int i = 0; i < m; i++)
    cin >> arr_x[i];
  for (int i = 0; i < m; i++)
    cin >> arr_y[i];

  for (int i = 0; i < m; i++) {
    int op = ops[i], x = arr_x[i], y = arr_y[i];
    if (op == 0) {
      bit_tree.update(x, y - nums[x]);
      nums[x] = y;
    } else {
      cout << (flag ? " " : "");
      int val = bit_tree.query(y) - bit_tree.query(x - 1);
      cout << val;
      flag = 1;
    }
  }
  cout << endl;
  return 0;
}
