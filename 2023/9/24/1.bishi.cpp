/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月24日 星期日 19时59分50秒
 ************************************************************************/

#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void dfs(vector<string> &grid, int n, int x, int y) {
  if (n == 1) {
    grid[x][y] = '*';
    grid[x + 1][y - 1] = grid[x + 1][y + 1] = '*';
    grid[x + 2][y - 2] = grid[x + 2][y] = grid[x + 2][y + 2] = '*';
    return ;
  }
  int h = 3 * pow(2, n - 2);
  dfs(grid, n - 1, x, y);
  dfs(grid, n - 1, x + h, y - h);
  dfs(grid, n - 1, x + h, y + h);
}

int main() {
  int n;
  cin >> n;
  int h = 3 * pow(2, n - 1);
  vector<string> grid(h + n, string(2 * h - 1, ' '));
  dfs(grid, n, 0, h - 1);
  for (int i = h; i < h + n; i++)
    grid[i][h - 1] = '*';
  for (auto && s : grid)
    cout << s << endl;
  return 0;
}
