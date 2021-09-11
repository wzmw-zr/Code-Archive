/*************************************************************************
	> File Name: 1.LeetCode600.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月11日 星期六 08时37分03秒
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

int dfs(int n, vector<int> &ones) {
    if (n == 0 || n == 1) return ones[n];
    int h = 32 - __builtin_clz(n);
    int ans = ones[h - 1];
    n -= 1 << (h - 1);
    if ((h >= 2) && ((n >> (h - 2)) & 1)) n = (1 << (h - 2)) - 1;
    ans += dfs(n, ones);
    return ans;
}

int findIntegers(int n) {
    vector<int> ones(33, 0);
    vector<int> zeros(33, 0);
    ones[1] = zeros[1] = 1;
    for (int i = 2; i <= 32; i++) {
        zeros[i] = zeros[i - 1] + ones[i - 1];
        ones[i] = zeros[i - 1];
    }
    ones[0] = 1;
    for (int i = 1; i <= 32; i++) ones[i] += ones[i - 1];
    return dfs(n, ones);
}

int main() {
    int n;
    cin >> n;
    cout << findIntegers(n) << endl;
    return 0;
}
