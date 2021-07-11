/*************************************************************************
	> File Name: 5.LeetCode1932.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月11日 星期日 23时01分39秒
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

const int MOD = 1e9 + 7;

void generate_valid_lines(int ind, int n, int num, vector<int> &valid_lines) {
    if (ind == n) {
        valid_lines.push_back(num);
        return ;
    }
    for (int i = 1; i <= 3; i++) {
        if (num % 10 == i) continue;
        generate_valid_lines(ind + 1, n, num * 10 + i, valid_lines);
    }
}

int can_neighbor(int x, int y, int m) {
    while (m--) {
        if ((x % 10) == (y % 10)) return 0;
        x /= 10, y /= 10;
    }
    return 1;
}

void generate_graph(vector<int> &valid_lines, unordered_map<int, vector<int>> &from, int &m) {
    for (int x : valid_lines) {
        from[x] = vector<int>(0);
        for (int y : valid_lines) {
            if (can_neighbor(x, y, m)) from[x].push_back(y);
        }
    }
}

int colorTheGrid(int m, int n) {
    vector<int> valid_lines;
    generate_valid_lines(0, m, 0, valid_lines);
    unordered_map<int, vector<int>> from;
    generate_graph(valid_lines, from, m);
    unordered_map<int, int> mp;
    for (int x : valid_lines) mp[x] = 1;
    for (int i = 1; i < n; i++) {
        unordered_map<int, int> temp;
        for (int x : valid_lines) {
            temp[x] = 0;
            for (int y : from[x]) temp[x] = (temp[x] + mp[y]) % MOD;
        }
        mp = temp;
    }
    int ans = 0;
    for (auto &&[x, cnt] : mp) ans = (ans + cnt) % MOD;
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << colorTheGrid(m, n) << endl;
    return 0;
}
