/*************************************************************************
	> File Name: 4.LeetCode1411.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月11日 星期日 22时40分25秒
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

void calculate_valid_line(int ind, int num, vector<int> &valid_lines) {
    if (ind == 3) {
        int one = num % 10, ten = (num / 10) % 10, hundred = (num / 100) % 10;
        if (one == ten || ten == hundred) return ;
        valid_lines.push_back(num);
        return ;
    }
    for (int i = 0; i < 3; i++) calculate_valid_line(ind + 1, num * 10 + i, valid_lines);
}

const int MOD = 1e9 + 7;

int is_valid(int x, int y) {
    int one_x = x % 10, ten_x = (x / 10) % 10, hundred_x = (x / 100) % 10;
    int one_y = y % 10, ten_y = (y / 10) % 10, hundred_y = (y / 100) % 10;
    if (one_x == one_y || ten_x == ten_y || hundred_x == hundred_y) return 0;
    return 1;
}

int numOfWays(int n) {
    vector<int> valid_lines;
    calculate_valid_line(0, 0, valid_lines);
    vector<unordered_map<int, int>> dp(n);
    for (int x : valid_lines) dp[0][x] = 1;
    for (int i = 1; i < n; i++) {
        for (int x : valid_lines) {
            for (int y : valid_lines) {
                if (is_valid(x, y)) dp[i][x] = (dp[i][x] + dp[i - 1][y]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int x : valid_lines) ans = (ans + dp[n - 1][x]) % MOD;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << numOfWays(n) << endl;
    return 0;
}
