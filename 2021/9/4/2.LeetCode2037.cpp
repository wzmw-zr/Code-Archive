/*************************************************************************
	> File Name: 2.LeetCode2037.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月04日 星期六 08时37分13秒
 ************************************************************************/

#include <iostream>
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

vector<vector<long>> multiply(vector<vector<long>> &x, vector<vector<long>> &y) {
    vector<vector<long>> ans(2, vector<long>(2, 0));
    ans[0][0] = (((x[0][0] * y[0][0]) % MOD) + ((x[0][1] * y[1][0]) % MOD)) % MOD;
    ans[0][1] = (((x[0][0] * y[0][1]) % MOD) + ((x[0][1] * y[1][1]) % MOD)) % MOD;
    ans[1][0] = (((x[1][0] * y[0][0]) % MOD) + ((x[1][1] * y[1][0]) % MOD)) % MOD;
    ans[1][1] = (((x[1][0] * y[0][1]) % MOD) + ((x[1][1] * y[1][1]) % MOD)) % MOD;
    return ans;
}

int fib(int n) {
    vector<vector<long>> m({{1, 1}, {1, 0}});
    vector<vector<long>> f({{1, 0}, {0, 1}});
    while (n) {
        if (n & 1) f = multiply(f, m);
        m = multiply(m, m);
        n >>= 1;
    }
    return f[1][0];
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
