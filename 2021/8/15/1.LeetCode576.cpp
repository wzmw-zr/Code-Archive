/*************************************************************************
	> File Name: 1.LeetCode576.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月15日 星期日 10时55分22秒
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

const long MOD = 1e9 + 7;

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int findPaths(int m, int n, int N, int i, int j) {
    if (N < 0) return 0;
    if (i < 0 || i >= m || j < 0 || j >= n) return 1;
    long ans = 0;
    for (int ind = 0; ind < 4; ind++) ans += 1L * findPaths(m, n, N - 1, i + dir[ind][0], j + dir[ind][1]);
    ans %= MOD;
    return ans;
}

int main() {
    return 0;
}
