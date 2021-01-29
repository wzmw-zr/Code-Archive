/*************************************************************************
	> File Name: 1.LeetCode778.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月30日 星期六 00时04分47秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

#define id(x, y) (n * (x) + (y))

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

struct UnionSet {
    int n;
    vector<int> fa;
    UnionSet(int n) : n(n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[a] = b;
        n--;
    }
};

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> water_elevation(n, vector<int>(n, 0));
    UnionSet u(n * n);
    int t = 1;
    while (1) {
        for (auto &x : water_elevation) {
            for (auto &y : x) y = t;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > water_elevation[i][j]) continue;
                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (grid[x][y] > water_elevation[x][y]) continue;
                    u.merge(id(i, j), id(x, y));
                }
            }
        }
        if (u.get(id(0, 0)) == u.get(id(n - 1, n - 1))) break;
        t++;
    }
    return t;
}

int main() {
    return 0;
}
