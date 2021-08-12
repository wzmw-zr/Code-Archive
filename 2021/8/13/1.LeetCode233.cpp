/*************************************************************************
	> File Name: 1.LeetCode233.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月13日 星期五 00时05分03秒
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
#include <cmath>
using namespace std;

vector<int> dp;

int cal_len(int n) {
    int len = 0;
    while (n) {
        n /= 10;
        len++;
    }
    return len;
}

int get_high(int n, int len) {
    for (int i = 0; i < len - 1; i++) n /= 10;
    return n;
}

int cal_one_count(int n) {
    if (n >= 0 && n <= 9) return n >= 1 ? 1 : 0;
    int len = cal_len(n);
    int h = get_high(n, len);
    int rest = n % (int) pow(10, len - 1);
    int ans = h * dp[len - 1] + cal_one_count(rest);
    if (h > 1) ans += (int) pow(10, len - 1);
    else ans += rest + 1;
    return ans;
}

int countDigitOne(int n) {
    dp = vector<int>(10, 0);
    for (int i = 1; i <= 9; i++) dp[i] = 10 * dp[i - 1] + pow(10, i - 1);
    return cal_one_count(n);
}

int main() {
    int n;
    cin >> n;
    cout << countDigitOne(n) << endl;
    return 0;
}
